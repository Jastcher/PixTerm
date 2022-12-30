#include "../include/Pixterm.h"
#include <thread>

int main() {

	PixTerm::Terminal term = PixTerm::Terminal(50,50);


	//float rot = 0.0f;
	//for (;;) {
	//	if (rot > 360.0f) rot = 0;
	//	rot += 0.01f;
	//	term.Clear(' ');

	//	glm::mat4 model = glm::mat4(1.0f);
	//	model = glm::translate(model, glm::vec3(10));
	//	model = glm::rotate(model, glm::radians(rot), glm::vec3(1.0f, 1.0f, 1.0f));
	//	model = glm::scale(model, glm::vec3(1.5f));

	//	//term.DrawTriangles(buffer, 'o', model);
	//	term.DrawQuad('z', model);

	//	term.DrawOverlay();
	//	term.Render();
	//}


	return 0;



	//term.PrintLogger();
}
