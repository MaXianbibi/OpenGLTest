#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Class\App\App.h"

#include "Class\ShadClass\ShaderClass.h"

//unsigned int CompileShader(unsigned int type, const std::string& source)
//{
//    unsigned int id = glCreateShader(type);
//    const char * src = source.c_str();
//    
//    glShaderSource(id, 1, &src, nullptr);
//    glCompileShader(id);
//
//    int result;
//    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
//    if (result == GL_FALSE)
//    {
//        int length;
//        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
//        char* message = (char*)alloca(length * sizeof(char));
//        glGetShaderInfoLog(id, length, &length, message);
//        std::cerr << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
//        std::cerr << message << std::endl;
//        glDeleteShader(id);
//        return 0;
//    }
//    return id;
//}
//
//static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
//
//{
//    unsigned int program = glCreateProgram();
//    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
//    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
//
//    glAttachShader(program, vs);
//    glAttachShader(program, fs);
//    glLinkProgram(program);
//    glValidateProgram(program);
//
//    glDeleteShader(vs);
//    glDeleteShader(fs);
//
//    return program;
//}

 
int main(void)
{
    App app;
    if (app.getStatus() == APP_FAIL)
        return -1;


        float positions[6] = {
	    	-0.5f, -0.5f,
	    	 0.0f,  0.5f,
	    	 0.5f, -0.5f
	    };


        unsigned int buffer;
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);


        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        ShaderClass shader;


        shader.LoadShader("./res/shaders/basic.txt");

        shader.debugShader();
        unsigned int prog = shader.CreateShader();
        


        //unsigned int program = shader.CreateShader(vertexShader, fragmentShader);

        glUseProgram(prog);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(app.getWindow()))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


       glDrawArrays(GL_TRIANGLES, 0, 3);


        /* Swap front and back buffers */
        glfwSwapBuffers(app.getWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}