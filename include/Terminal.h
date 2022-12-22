#pragma once

#include <vector>
#include "Buffer.h"

namespace PixTerm {
	
	struct Transform {
		int x;
		int y;
		unsigned int width = 1;
		unsigned int height = 1;
	};

	class Terminal {
	public:
		Terminal(unsigned int _width = 15, unsigned int _height = 10);
		~Terminal();

		bool Clear(unsigned char c);

		// for buffer
		bool DrawPoints(const Buffer& buffer, unsigned char c);
		bool DrawLines(const Buffer& buffer, unsigned char c);
		bool DrawTriangles(const Buffer& buffer, unsigned char c);

		// easy concept
		bool DrawPoint(const Transform& t, unsigned char c);
		// TODO when matrix transformations are added
		bool DrawLine(const Transform& t, unsigned char c);
		bool DrawTriangle(const Transform& t, unsigned char c);

		bool Render();
		bool DrawOverlay();

		bool PrintLogger();

		unsigned int width;
		unsigned int height;
	private:
		int GetX(float x);
		int GetY(float y);
		void EraseLine(int y);
		
		bool DrawPointMatrix(int x, int y, unsigned char c);
		bool DrawLineMatrix(int x1, int y1, int x2, int y2, unsigned char c);
		

		unsigned char* screen;
		unsigned char* screenUpdate;

		std::vector<std::string> logger;
	};

}
