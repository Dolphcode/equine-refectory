#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <glad/gl.h>

namespace shader {
	
	/**
	 * A minimal function for loading and compiling a shader program from a file using only vertex shaders and fragment shaders
	 * @param vShader The path to the vertex shader in disk
	 * @param fShader The path to the fragment shader in disk
	 * @return the compiled shader program gl object or NULL if fail
	 */
	GLuint loadProgramFromFile(std::string vShader, std::string fShader);

	/**
	 * A function for loading and compiler a shader program with optional parameters for tesselation and geometry shaders
	 * @param vShader The path to the vertex shader in disk
	 * @param fShader The path to the fragment shader in disk
	 * @param controlShader The path to the tesselation control shader or NULL if not provided
	 * @param evalShader The path to the tesselation evaluation shader or NULL if not provided
	 * @param geoShader The path to the geometry shader or NULL if not provided
	 * @return The compiled shader program gl object or NULL if fail
	 */
	GLuint loadProgramFromFileFull(std::string vShader, 
			std::string fShader, 
			std::string *controlShader, 
			std::string *evalShader, 
			std::string *geoShader);

}
