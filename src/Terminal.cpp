#include "../include/Pixterm.h"

namespace PixTerm {

	Terminal::Terminal(unsigned int _width, unsigned int _height)
		: width(_width), height(_height) {

		screen = (unsigned char*)malloc(width * height);
		screenUpdate = (unsigned char*)malloc(width * height);
		Clear(' ');
	}

	Terminal::~Terminal() {
		delete screen;
		delete screenUpdate;
	};

	bool Terminal::Clear(unsigned char c) {
		memset(screen, c, width * height);
		return 1;
	}

	bool Terminal::DrawPoints(const Buffer& buffer, unsigned char c) {
		for (int i = 0; i < buffer.mSize; i+=2) {
			int x = GetX(buffer.mData[i]); 
			int y = GetY(buffer.mData[i+1]); 
			logger.push_back("Drawing point in: " + std::to_string(x) + " ; " + std::to_string(y));
			screen[y * width + x] = c;
		}

		return 1;
	}

	bool Terminal::DrawLines(const Buffer &buffer, unsigned char c) {
		for (int i = 0; i < buffer.mSize; i+=2) {
						
		}

		return 1;
	}

	int Terminal::GetX(float x) {
		return width * (x + 1) / 2;
	}
	int Terminal::GetY(float y) {
		return abs( 1 - (int)(height * (y - 1) / 2));
	}

	void Terminal::EraseLine(int y) {
		logger.push_back("Erasing line: " + std::to_string(y));
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

}
