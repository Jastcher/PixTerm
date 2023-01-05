#include "Pixterm.h"

namespace PixTerm {

	bool Terminal::DrawPoints(const Buffer& buffer, unsigned char c) {
		for (int i = 0; i < buffer.mSize; i+=2) {
			int x = GetX(buffer.mData[i]); 
			int y = GetY(buffer.mData[i+1]); 
			DrawPoint(x, y, c);
		}

		return 1;
	}

	bool Terminal::DrawPoint(int x, int y, unsigned char c) {
		//logger.push_back("Drawing point in: " + std::to_string(x) + " ; " + std::to_string(y));
		if (x < 0 || y < 0 || x >= width || y >= height) return 0;
		screen[y * width + x] = c;

		return 1;
	}
}
