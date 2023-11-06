#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Window/Window.h"


enum APP_STATE {
	APP_FAIL = -1,
	APP_OK = 0,
};

typedef char appStatus;

class App
{
private:
	Window* win;
	appStatus status;


public:
	App();
	~App();


	bool 		init();
	bool		init(int width, int height, const char* title);

	// getter
	appStatus		getStatus() { return status; };
	Window*			getWindowClass() { return win; };
	GLFWwindow*		getWindow() { return win->getWindow(); };
};

