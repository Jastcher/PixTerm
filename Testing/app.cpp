#include "../include/Pixterm.h"
#include <thread>

int main() {

	PixTerm::Terminal term = PixTerm::Terminal(30,30);

	term.Clear(' ');

	float lineVertices[12] = { -0.5f, 0.0f,
							    0.5f, 0.0f,

							    0.5f, 0.0f,
								0.0f, 0.5f,

								0.0f, 0.5f,
								-0.5f, 0.0f

								 };

	float triangleVertices[6] = { -0.5f, -0.5f,
								  0.5f, -0.5f,
								  0.0f, 0.5f};


	PixTerm::Buffer lineBuffer(lineVertices, 12);
	PixTerm::Buffer TriangleBuffer(triangleVertices, 6);

	term.DrawLines(lineBuffer, 'a');
	term.DrawTriangles(TriangleBuffer, 'b');
	term.DrawOverlay();

	term.Render();

	term.PrintLogger();
}
