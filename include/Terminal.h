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
		Terminal(unsigned int _width = 15, unsigned int _height = 10);
		~Terminal();

		bool Clear(unsigned char c);

		// for buffer
		bool DrawPoints(const Buffer& buffer, unsigned char c);
		bool DrawLines(const Buffer& buffer, unsigned char c);
		bool DrawTriangles(const Buffer& buffer, unsigned char c, const glm::mat4& model = glm::mat4(1.0f));

		// easy concept
		bool DrawPoint(int x, int y, unsigned char c, const glm::mat4& model = glm::mat4(1.0f));
		bool DrawLine(int x1, int y1, int x2, int y2, unsigned char c, const glm::mat4& model = glm::mat4(1.0f));
		bool DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned char c, const glm::mat4& model = glm::mat4(1.0f));
		bool DrawQuad(int x, int y, int width, int height, unsigned char c, const glm::mat4& model = glm::mat4(1.0f));
		bool DrawQuad(unsigned char c, const glm::mat4& model = glm::mat4(1.0f));

		bool Render();
		bool DrawOverlay();

		bool PrintLogger();

		unsigned int width;
		unsigned int height;
	private:
		float quadVertices[12] = { -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f };
		Buffer quadBuffer;
		int GetX(float x);
		int GetY(float y);
		void EraseLine(int y);
		

		unsigned char* screen;
		unsigned char* screenUpdate;

		std::vector<std::string> logger;
	};

}
