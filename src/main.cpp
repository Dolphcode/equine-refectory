#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <fmt/base.h>

#include "rendering/shader.hpp"

int main(int argc, char **argv) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Hey Joey", NULL, NULL);
	
	glfwMakeContextCurrent(window);

	if (!gladLoadGL(glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD\n";
		return -1;
	}
		
	fmt::print("{}(@{}): Test\n", __FILE__, __LINE__);

	glViewport(0, 0, 800, 600);

	GLuint shaderProgram = shader::loadProgramFromFile("res/shaders/simple.vert", "res/shaders/simple.frag");

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.5f, -0.5f, 0.0f,
		0.0f, 1.0f, 0.0f,

		0.0f, 0.5f, 0.0f,
		0.0f, 0.0f, 1.0f,

		0.0f, 0.5f, 0.0f,
		1.0f, 0.0f, 0.0f,

		1.0f, 0.5f, 0.0f,
		0.0f, 1.0f, 0.0f,

		0.5f, -0.5f, 0.0f,
		0.0f, 0.0f, 1.0f
	};


	// Create the VAO and VBO
	GLuint VBO, VAO;
	glCreateVertexArrays(1, &VAO);
	glCreateBuffers(1, &VBO);
	glNamedBufferStorage(VBO, sizeof(vertices), vertices, 0);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Attribute vertex data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	
	// Cleanup
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		
		GLint startPoints[] = {0, 3};
		GLint counts[] = {3, 3};
		glMultiDrawArrays(GL_TRIANGLES, startPoints, counts, 2);

		glfwSwapBuffers(window);
	}
	
	glInvalidateBufferData(VBO); // ? Clear memory

	glfwTerminate();
	return 0;
}
