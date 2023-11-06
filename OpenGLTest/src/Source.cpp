#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Class\App\App.h"
#include "Class\ShadClass\ShaderClass.h"
 
int main(void)
{
    App app;
    if (app.getStatus() == APP_FAIL)
        return -1;


        float positions[ ] = {
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
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);


        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);




        unsigned int ibo;
        glGenBuffers(1, &ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);





        /// shader class
        ShaderClass shader;
        shader.LoadShader("./res/shaders/basic.txt");
        shader.debugShader();
        unsigned int prog = shader.CreateShader();
        glUseProgram(prog);


        /// App run / loop
    while (!glfwWindowShouldClose(app.getWindow()))
    {
        glClear(GL_COLOR_BUFFER_BIT);


        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);


        glfwSwapBuffers(app.getWindow());
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}