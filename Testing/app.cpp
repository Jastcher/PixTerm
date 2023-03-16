#include "../include/Pixterm.h"
#include <thread>

unsigned long long int prev = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
unsigned long long int now = 0;
float dt = 0;

int main() {

	PixTerm::Terminal term;

	std::this_thread::sleep_for(std::chrono::milliseconds(2));
	now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	dt = now - prev;
	dt /= 1000;
	prev = now;

	term.SetTitle(std::to_string(1/dt));

	term.Clear(' ');
	term.DrawTriangle(term.width/4, term.height/4, term.width-term.width/4, term.height/4-5, term.width/2, term.height-term.height/4, 'a', 'b');
	//term.DrawTriangle(term.width-term.width/4, term.height/4-5, term.width/4, term.height/4, term.width/2, term.height-term.height/4, 'a', 'b');
	//term.DrawTriangle(term.width/2, term.height-term.height/4, term.width-term.width/4, term.height/4-5, term.width/4, term.height/4, 'a', 'b');

	term.DrawOverlay();
	term.Render();

	//term.PrintLogger();

	return 0;
}
