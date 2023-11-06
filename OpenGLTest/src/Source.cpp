#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Class\App\App.h"
#include "Class\ShadClass\ShaderClass.h"
 

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLGetLog(#x, __FILE__, __LINE__));



static void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool GLGetLog(const char * function, const char * file, int line)
{
	while (GLenum error = glGetError())
	{
        std::cout << "[OpenGL Error] (" << error << ")" << std::endl <<
            function << std::endl << file << ":" << line << std::endl;
        return false;
	}

    return true;
}

int main(void)
{
    App app;
    if (app.getStatus() == APP_FAIL)
        return -1;


        float positions[] = {
	    	-0.5f, -0.5f,
	    	 0.5f,  -0.5f,
	    	 0.5f, 0.5f,
             -0.5f,  0.5f,
	    };

        unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

        /// vertex class ?
        unsigned int buffer;
        GLCall(glGenBuffers(1, &buffer));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
        GLCall(glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW));


        GLCall(glEnableVertexAttribArray(0));
        GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));




        unsigned int ibo;
        GLCall(glGenBuffers(1, &ibo));


        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));





        /// shader class
        ShaderClass shader;
        shader.LoadShader("./res/shaders/basic.txt");
        shader.debugShader();
        unsigned int prog = shader.CreateShader();
        GLCall(glUseProgram(prog));


        /// App run / loop
    while (!glfwWindowShouldClose(app.getWindow()))
    {
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

        GLCall(glfwSwapBuffers(app.getWindow()));
        GLCall(glfwPollEvents());
    }


    GLCall(glfwTerminate());
    return 0;
}