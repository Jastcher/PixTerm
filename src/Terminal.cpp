#include "../include/Pixterm.h"

namespace PixTerm {

	Terminal::Terminal() {
		struct winsize size;
		ioctl(STDERR_FILENO, TIOCGWINSZ, &size);
		width = size.ws_col/2;
		height = size.ws_row-1;
		Init();
	}
	Terminal::Terminal(unsigned int _width, unsigned int _height)
		: width(_width), height(_height) {
		Init();	
	}

	bool Terminal::Init() {
		screen = (unsigned char*)malloc(width * height);
		screenUpdate = (unsigned char*)malloc(width * height);
		Clear(' ');
		return 1;
	}

	Terminal::~Terminal() {
		EraseLine(height);
		keyCallbackTh->join();
		delete keyCallbackTh;
		delete screen;
		delete screenUpdate;
	};

	bool Terminal::SetTitle(const std::string& s) {
		std::cout << "\033]0;" << "fps: " << s << "\007";
	}

	bool Terminal::Clear(unsigned char c) {
		memset(screen, c, width * height);
		return 1;
	}

	bool Terminal::DrawQuad(int x, int y, int width, int height, unsigned char c) {
		bool first = DrawTriangle(x, y, x + width, y, x, y + height, c);
		bool second = DrawTriangle(x, y + height, x + width, y + height, x + width, y, c);
		return first || second;
	}

	int Terminal::GetX(float x) {
		return width * (x + 1) / 2;
	}
	int Terminal::GetY(float y) {
		return abs( 1 - (int)(height * (y - 1) / 2));
	}

	void Terminal::EraseLine(int y) {
		//logger.push_back("Erasing line: " + std::to_string(y));
		printf("\033[%d;%dH\033[K", y + 1, 1);
	}

	bool Terminal::Render() {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (screen[y * width + x] != screenUpdate[y * width + x]) {
					EraseLine(y);
					for (int i = 0; i < width; i++) {
						std::cout << screen[y * width + i] << ' ';

					}
					std::cout << '\n';
					break;
				}
			}
		}

		memcpy(screenUpdate, screen, width * height);
		return 1;
	}

	bool Terminal::DrawOverlay() {
		// top row
		for (int x = 0; x < width; x++) {
			screen[x] = '0'+x%10;
		}
		// left col
		for (int y = 0; y < height; y++) {
			screen[y * width] = '0'+y%10;
		}
		// right col
		for (int y = 0; y < height; y++) {
			screen[y * (width) + width-1] = '0'+y%10;
		}
		// bottom row 
		for (int x = 0; x < width; x++) {
			screen[(height-1) * (width) + x] = '0'+x%10;
		}

		return 1;
	}

	bool Terminal::PrintLogger() {
		for (const auto& row : logger) {
			std::cout << row << std::endl;
		}
		
		return 1;
	}

}
