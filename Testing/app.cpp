#include "../include/Pixterm.h"
#include <thread>

int main() {

	PixTerm::Terminal term = PixTerm::Terminal();

	term.Clear('x');

	float pointVertices[6] = { -0.5f, 0.0f,
							    0.5f, 0.0f,
								0.0f, 0.5f };

	PixTerm::Buffer pointBuffer(pointVertices, 6);

	term.DrawPoints(pointBuffer, 'a');
	term.Render();

	for (int i = 0; i < 5; i++) {
		term.Clear('a' + i);
		term.Render();
	}

}
