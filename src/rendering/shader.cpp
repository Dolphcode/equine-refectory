#include <fmt/base.h>

#include "log.hpp"

#include "rendering/shader.hpp"

#define INFO_LOG_MAX_LENGTH 512

GLuint shader::loadProgramFromFileFull(std::string vShaderPath, std::string fShaderPath, std::string *controlShaderPath, std::string *evalShaderPath, std::string *geoShaderPath) {
	// Declare all shader variables ahead of time
	GLuint vShader, fShader, controlShader = 0, evalShader = 0, geoShader = 0;

	// Contents buffer for shader file contents
	std::string contents{}, infoLog(INFO_LOG_MAX_LENGTH, 0);
	const char *source;	
	int success{};

	// Attempt to open the vertex shader
	std::ifstream vShaderFile( vShaderPath );
	if (vShaderFile.is_open()) {
		// Read the shader file contents
		vShaderFile.seekg(0, std::ios::end);
		contents.resize(vShaderFile.tellg());
		vShaderFile.seekg(0, std::ios::beg);
		vShaderFile.read(&contents[0], contents.size());

		// Create the shader and associate the source code
		vShader = glCreateShader(GL_VERTEX_SHADER);
		if (!vShader) {
			LOGERR << "failed to create vertex shader object\n";
			return 0;
		}
		source = contents.c_str();
		glShaderSource(vShader, 1, &source, NULL); 

		// Compile and print debug output if failed
		glCompileShader(vShader);
		glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vShader, INFO_LOG_MAX_LENGTH, NULL, &infoLog[0]);
			LOGERR << "failed to compile vertex shader:\n" << infoLog << '\n';
			return 0;
		}
		
		vShaderFile.close(); // Close stream when complete
	} else {
		LOGERR << "failed to open vertex shader file at path\"" << vShaderPath << "\"\n";
		return 0;
	}

	// Attempt to open the fragment shader
	std::ifstream fShaderFile( fShaderPath );
	if (fShaderFile.is_open()) {
		// Read the shader file contents
		fShaderFile.seekg(0, std::ios::end);
		contents.resize(fShaderFile.tellg());
		fShaderFile.seekg(0, std::ios::beg);
		fShaderFile.read(&contents[0], contents.size());

		// Create the shader and associate the source code
		fShader = glCreateShader(GL_FRAGMENT_SHADER);
		if (!fShader) {
			LOGERR << "failed to create fragment shader object\n";
			return 0;
		}
		source = contents.c_str();
		glShaderSource(fShader, 1, &source, NULL); 

		// Compile and print debug output if failed
		glCompileShader(fShader);
		glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fShader, INFO_LOG_MAX_LENGTH, NULL, &infoLog[0]);
			LOGERR << "failed to compile fragment shader:\n" << infoLog << '\n';
			return 0;
		}

		fShaderFile.close();
	} else {
		LOGERR << "failed to open fragment shader file at path\"" << fShaderPath << "\"\n";
		return 0;
	}

	// TODO: Implement loading for tesselation and geometry shaders

	// Create the shader program
	GLuint program{ glCreateProgram() };
	if (!program) {
		LOGERR << "failed to create shader program\n";
		return 0;
	}
	
	// Link each shader
	glAttachShader(program, vShader);
	glAttachShader(program, fShader);
	glLinkProgram(program);	
	// TODO: Implement linking tesselation and geometry shaders
	
	// Debug
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, INFO_LOG_MAX_LENGTH, NULL, &infoLog[0]);
		LOGERR << "failed to link program:\n" << infoLog << '\n';
		return 0;
	}

	// Cleanup
	glDeleteShader(vShader);
	glDeleteShader(fShader);
	
	// Successful program completion
	fmt::print("{}(@{}): Successfully compiled and linked shader program\n", __FILE__, __LINE__);
	return program;
}

GLuint shader::loadProgramFromFile(std::string vShader, std::string fShader) {
	return shader::loadProgramFromFileFull(vShader, fShader, NULL, NULL, NULL);	
}
