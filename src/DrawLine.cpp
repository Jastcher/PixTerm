#include "Pixterm.h"

namespace PixTerm {

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

	bool Terminal::DrawLine(int x1, int y1, int x2, int y2, unsigned char c) {
		//logger.push_back("Drawing line in: " + std::to_string(x1) + " , " + std::to_string(y1) + " and " + std::to_string(x2) + " , " + std::to_string(y2));
		int dx = x2-x1;
		int dy = y2-y1;

		if (!dx || !dy) { 
			//std::cout << x1 << ";" << y1 << " .. " << x2 << ";" << y2 << std::endl;
			DrawPoint(x1, y1, c);
			return 1;
		}


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
				DrawPoint(x, y, c);
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
				DrawPoint(x, y, c);
			}

		}
		
		return 1;

	}

}
