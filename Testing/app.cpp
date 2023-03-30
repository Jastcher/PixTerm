#include "../include/Pixterm.h"
#include <thread>

unsigned long long int prev = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
unsigned long long int now = 0;
float dt = 0;

float* vertices = new float[]{
	-0.5f, -0.5f,
	 0.5f, -0.5f,
	0.0f,   0.5f,
};

int main() {

	PixTerm::Terminal term;



	PixTerm::Buffer buff(vertices, 6);

	//term.DrawTriangle(term.width/4, term.height/4, term.width-term.width/4, term.height/4-5, term.width/2, term.height-term.height/4, 'a', 'b');
	for (float i = 0; i > -1; i+=10*dt) {
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
		now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		dt = now - prev;
		dt /= 1000;
		prev = now;

		term.SetTitle(std::to_string(1/dt));

		term.Clear(' ');
		glm::mat4 model(1.0f);
		model = glm::rotate(model, glm::radians((float)i), glm::vec3(1.0f));
		term.DrawTriangles(buff, 'c', 0, model);

		glm::mat4 model2(1.0f);
		model2 = glm::translate(model2, glm::vec3(0.5f, 0.0f, 0.0f));
		model2 = glm::rotate(model2, glm::radians((float)i), glm::vec3(1.0f));
		term.DrawTriangles(buff, 'c', 'f', model2);
		//term.DrawTriangle(term.width-term.width/4, term.height/4-5, term.width/4, term.height/4, term.width/2, term.height-term.height/4, 'a', 'b');
		//term.DrawTriangle(term.width/2, term.height-term.height/4, term.width-term.width/4, term.height/4-5, term.width/4, term.height/4, 'a', 'b');

		term.DrawOverlay();
		term.Render();
	}
	//term.PrintLogger();

	return 0;
}
