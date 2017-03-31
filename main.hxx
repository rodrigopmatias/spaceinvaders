#ifndef __MAIN_H__
#define __MAIN_H__

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <thread>

void framebufferSizeCallback(GLFWwindow * window, int width, int height);
void keyboardCallback(GLFWwindow * window, int key, int scancode, int action, int mode);
void renderWorld(GLFWwindow * window);

#endif
