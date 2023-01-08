#include "Pixterm.h"
#include <thread>
#include <termios.h>

namespace PixTerm {
	bool Terminal::SetKeyCallback(const std::function<void (char)>& fn) {
		keyCallback = fn;
		keyCallback('a');

		keyCallbackTh = new std::thread(&Terminal::GetKeyInput, this);

		return 1;
	}

	void Terminal::GetKeyInput() {
		char c;

		struct termios old_tio, new_tio;
		tcgetattr(STDIN_FILENO, &old_tio);  // get current terminal settings

		new_tio = old_tio;  // make a copy of the old settings
		new_tio.c_lflag &= ~ICANON;  // disable buffered input
		new_tio.c_lflag &= ~ECHO;  // disable echo mode

		tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);  // apply the new settings
		while (1) {
			c = getchar();  // read a single character from the terminal
			keyCallback(c);
		}

		tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);  // restore the old settings


	}

}
