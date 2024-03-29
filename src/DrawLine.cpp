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

	bool Terminal::DrawLine(int x1, int y1, int x2, int y2, unsigned char c, std::vector<Point>* vec) {
		std::vector<Point> vec1;
		//logger.push_back("Drawing line in: " + std::to_string(x1) + " , " + std::to_string(y1) + " and " + std::to_string(x2) + " , " + std::to_string(y2));
		int dx = x2-x1;
		int dy = y2-y1;

		int i,j;
		if (!dx && !dy) { 
			//std::cout << x1 << ";" << y1 << " .. " << x2 << ";" << y2 << std::endl;
			//DrawPoint(x1, y1, c);
			vec1.push_back({x1, y1});
		}


		else if (abs(x1 - x2) > abs(y1 - y2)) {

			if (x1 > x2) {
				i = x2;
				j = x1;
			//std::cout << "\nfirst if  " << i << " " << j << " " << x1 << " " << y1 << " " << dy << " "  << dx << std::endl;
			} else {
				i = x1;
				j = x2;
				dx *= -1;
				dy *= -1;
				x1 = x2;
				y1 = y2;
			//std::cout << "\nsecond if " << i << " " << j << " " << x1 << " " << y1 << " " << dy << " "  << dx << std::endl;
			}

			for (int x = i; x <= j; x++) {
				int y = y1 + dy * (x-x1) / dx;
				//DrawPoint(x, y, c);
				vec1.push_back({x, y});
			}

		} else {

			if  (y1 > y2) {
				i = y2;
				j = y1;
			} else {
				i = y1;
				j = y2;
				dx *= -1;
				dy *= -1;
				x1 = x2;
				y1 = y2;
			}

			for (int y = i; y <= j; y++) {
				int x = x1 + dx * (y-y1) / dy;
				//DrawPoint(x, y, c);
				vec1.push_back({x, y});
			}

		}

		for (auto& i : vec1) {
			DrawPoint(i.x, i.y, c);
			if(vec)
			vec->push_back(i);
		}
		
		return 1;

	}

}
