#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#define DEFAULT_WINDOW_TITLE "OpenGLTest"

enum DEFAULT_WINDOW_SIZE
{
	DEFAULT_WINDOW_WIDTH = 800,
	DEFAULT_WINDOW_HEIGHT = 600
};

enum WINDOW_STATE {
	SUCCESS = 0,
	FAILURE = 1,
};

typedef bool State;

class Window
{
private:
	GLFWwindow* window;
	int windowWidth;
	int windowHeight;
	const char* windowTitle;

	State windowState;


public:
	Window();
	~Window();
	Window(int width, int height, const char* name);

	
	bool init(void);
	void setupWindow(void);
	void handleErrors(void);

	// getters
	GLFWwindow*		getWindow(void);
	bool			getState(void);

	

};

