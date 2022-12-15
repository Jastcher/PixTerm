#include "../include/Pixterm.h"
#include <thread>

int main() {

	PixTerm::Terminal term = PixTerm::Terminal(30,25);

	term.Clear(' ');

	float pointVertices[6] = { -0.5f, 0.0f,
							    0.5f, 0.0f,
								0.0f, 0.5f };

	PixTerm::Buffer pointBuffer(pointVertices, 6);

	term.DrawPoints(pointBuffer, 'a');
	term.Render();


}
