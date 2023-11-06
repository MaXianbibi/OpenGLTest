#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <string>

#include <sstream>

class ShaderClass
{
private:
	std::string vertexShader;
	std::string fragmentShader;

	unsigned int CompileShader(unsigned int type, const std::string& source);
public:
	ShaderClass() = default;
	~ShaderClass() = default;

	unsigned int CreateShader(void);
	bool LoadShader(const std::string& filePath);

	void debugShader(void);

};

