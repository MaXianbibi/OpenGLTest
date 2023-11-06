#include "Window.h"


Window::Window() : Window(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, DEFAULT_WINDOW_TITLE) { }

Window::Window(int width, int height, const char* title) : windowHeight(height), windowWidth(width), windowTitle(title)
{
    if (init() == FAILURE) {
        handleErrors();
	}
}

Window::~Window()
{
}

bool Window::init(void)
{
    if (!glfwInit()) {
        std::cerr << "GLFW initialization failed!" << std::endl;
        return FAILURE;
    }
    setupWindow();
    if (!window) {
        std::cerr << "Window creation failed!" << std::endl;
        glfwTerminate();
        return FAILURE;
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        std::cerr << "GLEW initialization failed!" << std::endl;
        return FAILURE;
    }
    std::cout << glGetString(GL_VERSION) << std::endl;
    windowState = SUCCESS;
}


void Window::setupWindow(void) {
    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
}

void Window::handleErrors(void) {
    windowState = FAILURE;
}

GLFWwindow*  Window::getWindow(void) {
    return window;
}

bool Window::getState(void) {
    return windowState;
}