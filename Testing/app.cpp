#include "../include/Pixterm.h"
#include <thread>

int main() {

	PixTerm::Terminal term = PixTerm::Terminal(30,25);

	term.Clear(' ');

	float pointVertices[12] = { -0.5f, 0.0f,
							    0.5f, 0.0f,

							    0.5f, 0.0f,
								0.0f, 0.5f,

								0.0f, 0.5f,
								-0.5f, 0.0f

								 };

	PixTerm::Buffer pointBuffer(pointVertices, 12);

	term.DrawLines(pointBuffer, 'a');
	term.Render();


}
