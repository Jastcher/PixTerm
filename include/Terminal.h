#pragma once

#include <vector>
#include "Buffer.h"

namespace PixTerm {
	
	class Terminal {
	public:
		Terminal(unsigned int _width = 15, unsigned int _height = 10);
		~Terminal();

		bool Clear(unsigned char c);

		bool DrawPoints(const Buffer& buffer, unsigned char c);
		bool DrawLines(const Buffer& buffer, unsigned char c);
		bool DrawTriangles(const Buffer& buffer, unsigned char c);

		bool Render();
		bool DrawOverlay();

		bool PrintLogger();

		unsigned int width;
		unsigned int height;
	private:
		int GetX(float x);
		int GetY(float y);
		void EraseLine(int y);
		
		bool DrawPointMatrix(unsigned int x, unsigned int y, unsigned char c);
		bool DrawLineMatrix(int x1, int y1, int x2, int y2, unsigned char c);

		unsigned char* screen;
		unsigned char* screenUpdate;

		std::vector<std::string> logger;
	};

}
