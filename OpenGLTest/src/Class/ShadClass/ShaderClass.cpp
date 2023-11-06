#include "ShaderClass.h"


unsigned int ShaderClass::CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();

    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cerr << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
        std::cerr << message << std::endl;
        glDeleteShader(id);
        return 0;
    }
    return id;
}

unsigned int ShaderClass::CreateShader(void)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

bool ShaderClass::LoadShader(const std::string& filePath)
{
    std::ifstream stream	 (filePath);

if (!stream.is_open())
	{
		std::cout << "Could not open file " << filePath << std::endl;
		return false;
	}

    enum class shaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];

    shaderType type = shaderType::NONE;

    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
			{
                type = shaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
                type = shaderType::FRAGMENT;
			}
        }
        else
        {
            if (type == shaderType::NONE)
			{
				std::cout << "Error: Shader type not set" << std::endl;
				return false;
			}
			else
			{
				ss[(int)type] << line << "\n";
			}
        }
    }
    this->vertexShader = ss[(int)shaderType::VERTEX].str();
    this->fragmentShader = ss[(int)shaderType::FRAGMENT].str();
    return true;
}


void ShaderClass::debugShader(void)
{
    std::cout << "DEUBG SHADER" << std::endl;


    std::cout << "VERTEX SHADER" << std::endl;
    std::cout << vertexShader << std::endl;

	std::cout << "FRAGMENT SHADER" << std::endl;
    std::cout << fragmentShader << std::endl;
}