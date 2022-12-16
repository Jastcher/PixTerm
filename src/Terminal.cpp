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
			DrawPointMatrix(x, y, c);
		}

		return 1;
	}
	bool Terminal::DrawPointMatrix(unsigned int x, unsigned int y, unsigned char c) {
		logger.push_back("Drawing point in: " + std::to_string(x) + " ; " + std::to_string(y));
		screen[y * width + x] = c;
		return 1;
	}

	bool Terminal::DrawLines(const Buffer &buffer, unsigned char c) {
		for (int i = 0; i < buffer.mSize; i+=4) {
			int x1 = GetX(buffer.mData[i]); 
			int y1 = GetY(buffer.mData[i+1]); 
			int x2 = GetX(buffer.mData[i+2]); 
			int y2 = GetY(buffer.mData[i+3]); 
			
			int dx = x2-x1;
			int dy = y2-y1;

			for (int x = x1; x < x2; x++) {
				int y = y1 + dy * (x-x1) / dx;
				DrawPointMatrix(x, y, c);
			}
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
