#include "../include/Pixterm.h"

namespace PixTerm {

	Terminal::Terminal(unsigned int _width, unsigned int _height)
		: width(_width), height(_height) {
		
		quadBuffer.mData = quadVertices;
		quadBuffer.mSize = 12;

		screen = (unsigned char*)malloc(width * height);
		screenUpdate = (unsigned char*)malloc(width * height);
		Clear(' ');
	}

	Terminal::~Terminal() {
		EraseLine(height);
		std::cout << "DESTROYING" << std::endl;
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
			DrawPoint(x, y, c);
		}

		return 1;
	}

	bool Terminal::DrawLines(const Buffer &buffer, unsigned char c) {
		for (int i = 0; i < buffer.mSize; i+=4) {
			int x1 = GetX(buffer.mData[i]); 
			int y1 = GetY(buffer.mData[i+1]); 
			int x2 = GetX(buffer.mData[i+2]); 
			int y2 = GetY(buffer.mData[i+3]); 

			DrawLine(x1, y1, x2, y2, c);
		}

		return 1;
	}


	bool Terminal::DrawTriangles(const Buffer &buffer, unsigned char c, const glm::mat4& model) {
		for (int i = 0; i < buffer.mSize; i += 6) {
			int x1 = GetX(buffer.mData[i]); 
			int y1 = GetY(buffer.mData[i+1]); 
			int x2 = GetX(buffer.mData[i+2]); 
			int y2 = GetY(buffer.mData[i+3]); 
			int x3 = GetX(buffer.mData[i+4]); 
			int y3 = GetY(buffer.mData[i+5]); 

			DrawTriangle(x1, y1, x2, y2, x3, y3, c, model);

		}

		return 1;
	}

	bool Terminal::DrawPoint(int x, int y, unsigned char c, const glm::mat4& model) {
		logger.push_back("Drawing point in: " + std::to_string(x) + " ; " + std::to_string(y));
		glm::vec2 pos = (model * glm::vec4(x,y,0,1));
		if (pos.x < 0 || pos.y < 0 || pos.x > width || pos.y > height) return 0;
		screen[(int)pos.y * width + (int)pos.x] = c;

		return 1;
	}

	bool Terminal::DrawLine(int x1, int y1, int x2, int y2, unsigned char c, const glm::mat4& model) {
		logger.push_back("Drawing line in: " + std::to_string(x1) + " , " + std::to_string(y1) + " and " + std::to_string(x2) + " , " + std::to_string(y2));
		int dx = x2-x1;
		int dy = y2-y1;

		int i,j;
		if (abs(x1 - x2) > abs(y1 - y2)) {

			if (x1 > x2) {
				i = x2;
				j = x1;
			} else {
				i = x1;
				j = x2;
			}

			for (int x = i; x <= j; x++) {
				int y = y1 + dy * (x-x1) / dx;
				DrawPoint(x, y, c, model);
			}

		} else {

			if  (y1 > y2) {
				i = y2;
				j = y1;
			} else {
				i = y1;
				j = y2;
			}

			for (int y = i; y <= j; y++) {
				int x = x1 + dx * (y-y1) / dy;
				DrawPoint(x, y, c, model);
			}

		}
		
		return 1;

	}

	bool Terminal::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned char c, const glm::mat4& model) {
		logger.push_back("Drawing triangle in: " + std::to_string(x1) + " , " + std::to_string(y1) + " and " + std::to_string(x2) + " , " + std::to_string(y2) + " and " + std::to_string(x3) + " , " + std::to_string(y3));
		bool first = DrawLine(x1, y1, x2, y2, c, model);
		bool second = DrawLine(x2, y2, x3, y3, c, model);
		bool third = DrawLine(x3, y3, x1, y1, c, model);
		return first || second || third;
	}

	bool Terminal::DrawQuad(int x, int y, int width, int height, unsigned char c, const glm::mat4& model) {
		logger.push_back("Drawing quad in: " + std::to_string(x) + " , " + std::to_string(y) + " width: " + std::to_string(width) + " height: " + std::to_string(height)); 
		bool first = DrawTriangle(x, y, x + width, y, x, y + height, c, model);
		bool second = DrawTriangle(x, y + height, x + width, y + height, x + width, y, c, model);
		return first || second;
	}
	bool Terminal::DrawQuad(unsigned char c, const glm::mat4& model) {
		return DrawTriangles(quadBuffer, c, model);
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
