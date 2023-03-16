#include "../../include/Pixterm.h"
#include <thread>

unsigned long long int prev = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
unsigned long long int now = 0;
float dt = 0;

int main() {

	PixTerm::Terminal term;

	PixTerm::Buffer teaPot("lamp.obj");

	std::cout << teaPot.mData[0] << std::endl;

	std::cout << std::endl;
	std::cout << teaPot.mSize << std::endl;

	// clear whole screen
	term.Clear(' ');


	float rot = 0.0f;
	for (; rot < 360.0f; rot += 15.0f*dt) {
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
		now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

		dt = now - prev;
		dt /= 1000;
		prev = now;

		//std::cout << "\ndt: " << dt << "s fps: " << 1/dt << std::endl;
		std::cout << "\033]0;" << "fps: " << 1/dt << "\007";

		term.Clear(' ');
		glm::mat4 model = glm::mat4(1.0f);
		//model = glm::translate(model, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.5f));
		model = glm::rotate(model, glm::radians(rot), glm::vec3(1.0f, 1.0f, 0.0f));
		term.DrawTriangles(teaPot, 'x', model);

	// draw borders
	term.DrawOverlay();

	// render to terminal
	term.Render();
	}

	return 0;
}
