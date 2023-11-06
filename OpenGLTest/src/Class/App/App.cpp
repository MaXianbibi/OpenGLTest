#include "App.h"
#include <iostream>


App::App()
{
	win = new Window;
	if (win->getState() == FAILURE)
	{
		std::cerr << "Error: Window could not be created" << std::endl;
		status = APP_FAIL;
	}
	else
		status = APP_OK;
}


//bool app::init()

bool App::init(void)
{
	return true;

}


App::~App()
{
	delete win;
}