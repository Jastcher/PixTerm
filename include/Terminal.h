#pragma once
#include "../include/Pixterm.h"

namespace PixTerm {
	
	class Terminal {
	public:
		Terminal();
		~Terminal();

		bool Clear(unsigned char c);

		bool DrawPoints(const Buffer& buffer, unsigned char c);

		bool Render();

		unsigned int width;
		unsigned int height;
	private:
		int GetX(float x);
		int GetY(float y);
		void EraseLine(int y);

		unsigned char* screen;
		unsigned char* screenUpdate;

		std::vector<std::string> logger;
	};

}
