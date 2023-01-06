#pragma once

#include <vector>
#include "Buffer.h"
#include"glm/glm.hpp"

namespace PixTerm {

	struct Transform {
		glm::vec2 position;
		glm::vec2 scale;
		glm::vec2 rotation;
	};
	
	class Terminal {
	public:
		Terminal();
		Terminal(unsigned int _width, unsigned int _height);
		~Terminal();

		bool Init();

		bool Clear(unsigned char c);

		// for buffer
		bool DrawPoints(const Buffer& buffer, unsigned char c);
		bool DrawLines(const Buffer& buffer, unsigned char c);
		bool DrawTriangles(const Buffer& buffer, unsigned char c, const glm::mat4& model = glm::mat4(1.0f));

		// easy concept
		bool DrawPoint(int x, int y, unsigned char c);
		bool DrawLine(int x1, int y1, int x2, int y2, unsigned char c);
		bool DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned char c);
		bool DrawQuad(int x, int y, int width, int height, unsigned char c);

		bool DrawOverlay();

		bool Render();

		bool PrintLogger();

		unsigned int width;
		unsigned int height;
		int GetX(float x);
		int GetY(float y);
	private:
		void EraseLine(int y);
		
		unsigned char* screen;
		unsigned char* screenUpdate;

		std::vector<std::string> logger;
	};

}
