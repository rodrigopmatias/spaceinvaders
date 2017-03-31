#ifndef __MAIN_H__
#define __MAIN_H__

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <thread>
#include <chrono>

typedef std::chrono::duration<int, std::ratio<1, 1000>> frame_duration;

void framebufferSizeCallback(GLFWwindow * window, int width, int height);
void keyboardCallback(GLFWwindow * window, int key, int scancode, int action, int mode);
void renderWorld(GLFWwindow * window);
void statusLog(GLFWwindow * window);

void ticker(GLFWwindow * window);

unsigned int frameCount;

#endif
