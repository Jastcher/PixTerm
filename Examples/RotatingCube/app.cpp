#include "../../include/Pixterm.h"
#include <thread>

unsigned long long int prev = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
unsigned long long int now = 0;
float dt = 0;

int main() {

	PixTerm::Terminal term;

	float verticesCube[] = {
	    -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f
	};

	// make buffer
	PixTerm::Buffer buffCube(verticesCube, sizeof(verticesCube) / sizeof(float), true);

	float rot = 0.0f;
	for (; rot <= 3600.0f; rot += 15.0f*dt) {
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
		now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

		dt = now - prev;
		dt /= 1000;
		prev = now;

		// set console title to fps
		std::cout << "\033]0;" << "fps: " << 1/dt << "\007";

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::rotate(model, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

		glm::mat4 projection = glm::mat4(1.0f);
		//projection = glm::perspective(glm::radians(90.0f), term.width/(float)term.height, 0.01f, 100.0f);

		glm::mat4 view = glm::mat4(1.0f);
		//view = glm::lookAt(glm::vec3(0.0f), glm::vec3(0.0f) + glm::vec3(0.0f,0.0f,-1.0f), glm::vec3(0.0f,1.0f,0.0f));

		// clear whole screen
		term.Clear(' ');

		// draw cube
		term.DrawTriangles(buffCube, 'x', projection * view * model);

		// draw borders
		term.DrawOverlay();

		// render to terminal
		term.Render();
	}

	return 0;
}
