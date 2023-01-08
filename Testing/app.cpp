#include "../include/Pixterm.h"
#include <thread>

unsigned long long int prev = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
unsigned long long int now = 0;
float dt = 0;

void aaa(char);

float inc = 15.0f;

int main() {

	PixTerm::Terminal term;
	term.SetKeyCallback(std::bind(&aaa, std::placeholders::_1));

	float vertices3D[18] = { -0.5f,-0.5f,-0.5f,
						    0.5f,-0.5f,-0.5f,
							0.5f, 0.5f,-0.5f,
							0.5f, 0.5f,-0.5f,
						   -0.5f, 0.5f,-0.5f,
						   -0.5f,-0.5f,-0.5f };

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
	}
;

	float vertices[12] = { -0.5f,-0.5f,
						    0.5f,-0.5f,
							0.5f, 0.5f,
							0.5f, 0.5f,
						   -0.5f, 0.5f,
						   -0.5f,-0.5f,};

	PixTerm::Buffer buff(vertices, 12, false);
	PixTerm::Buffer buff3D(vertices3D, 18, true);
	PixTerm::Buffer buffCube(verticesCube, sizeof(verticesCube) / sizeof(float), true);


	float i = 0.0f;
	for (; i <= 3600.0f; i+=inc*dt) {
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
		now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

		dt = now - prev;
		dt /= 1000;
		prev = now;

		//std::cout << "\ndt: " << dt << "s fps: " << 1/dt << std::endl;
		std::cout << "\033]0;" << "fps: " << 1/dt << "\007";

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.0f,0.0f,0.0f));
		model = glm::rotate(model, glm::radians(i), glm::vec3(1.0f, 1.0f, 1.0f));

		glm::mat4 model2 = glm::mat4(1.0f);
		model2 = glm::translate(model2, glm::vec3(1.0f, 0.0f, 0.0f));
		model2 = glm::rotate(model2, glm::radians(i), glm::vec3(0.0f, 1.0f, 1.0f));

		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(90.0f), term.width/(float)term.height, 0.01f, 100.0f);
//
		glm::mat4 view = glm::mat4(1.0f);
		view = glm::lookAt(glm::vec3(0.0f), glm::vec3(0.0f) + glm::vec3(0.0f,0.0f,-1.0f), glm::vec3(0.0f,1.0f,0.0f));

		term.Clear(' ');
		//term.DrawTriangle(20, 9, 20, 9, 19, 27,'c');
		//std::cout << "DRAWING TRIANGLE WITH ROT: " << i << std::endl;
		//term.DrawTriangles(buff, 'x', projection * view * model);
		//term.DrawTriangles(buff3D, 'y', projection * view * model);
		term.DrawTriangles(buffCube,'a', projection * view * model);
		term.DrawTriangles(buffCube,'b', projection * view * model2);
		//std::cout << "DRAWN" << std::endl;
		//term.DrawQuad('r', model);
		term.DrawOverlay();
		term.Render();
	}


	return 0;
}

void aaa(char c) {
	switch (c) {
		case 'a':
			inc += 1.0f;
			break;
		case 'd':
			inc -= 1.0f;
			break;
	};

}
