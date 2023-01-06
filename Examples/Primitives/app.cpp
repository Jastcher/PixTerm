#include "../../include/Pixterm.h"
#include <thread>

unsigned long long int prev = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
unsigned long long int now = 0;
float dt = 0;

int main() {

	PixTerm::Terminal term;

	// define vertices for cube
	float vertices[12] = {
		// triangle one
		-0.5f,-0.5f,
		 0.5f,-0.5f,
		 0.5f, 0.5f,
		// triangle two
		 0.5f, 0.5f,
		-0.5f, 0.5f,
		-0.5f,-0.5f, 
	};

	// make buffer
	PixTerm::Buffer buff(vertices, sizeof(vertices)/sizeof(float));

	// clear whole screen
	term.Clear(' ');

	// draw triangle by vertex positions in screen space
	term.DrawTriangle(term.width/4, term.height/4, term.width-term.width/4, term.height/4, term.width/2, term.height-term.height/4, 'a');

	// draw triangles by buffer in world space
	// transform by scale
	glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	// transform by position
	model = glm::translate(model, glm::vec3(1.0f, -1.0f, 0.0f));
	term.DrawTriangles(buff, 'b', model);

	// draw line
	term.DrawLine(term.width/10, term.height/2, term.width/3, term.height-term.height/6, 'c');


	// draw borders
	term.DrawOverlay();

	// render to terminal
	term.Render();

	return 0;
}
