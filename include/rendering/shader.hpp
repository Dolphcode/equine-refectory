#pragma once
#include <glad/gl.h>

struct Shader {
	unsigned int id = 0;

	int loadShaderProgFromFile(const char*	vertexShader,
			const char*		fragmentShader);
};
	
