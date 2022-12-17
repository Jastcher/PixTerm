#include "../include/Pixterm.h"
#include <thread>

int main() {

	PixTerm::Terminal term = PixTerm::Terminal(50,50);

	term.Clear(' ');

	float lineVertices[12] = { -0.5f, 0.0f,
							    0.5f, 0.0f,

							    0.5f, 0.0f,
								0.0f, 0.5f,

								0.0f, 0.5f,
								-0.5f, 0.0f
								 };

	float triangleVertices[6] = { -1.5f, -0.5f,
								  0.5f, -0.5f,
								  0.0f, 0.5f
								};

	float vertices[4] {
		-1.0f, 0.2f,
		 1.0f, -0.2f
	};


	PixTerm::Buffer lineBuffer(lineVertices, 12);
	PixTerm::Buffer TriangleBuffer(triangleVertices, 6);
	PixTerm::Buffer buffer(vertices, 4);

	//term.DrawLines(lineBuffer, 'a');
	term.DrawTriangles(TriangleBuffer, 'b');
	//term.DrawLines(buffer, '?');
	//term.DrawPoint({25,25}, 'p');
	//term.DrawPoint({-25,15}, 'p');
	term.DrawOverlay();
	term.Render();


	term.PrintLogger();
}
