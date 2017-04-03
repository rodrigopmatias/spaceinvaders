#ifndef __GAME_WORLD_H__
#define __GAME_WORLD_H__

#include "object.hxx"
#include "aircraft.hxx"

#include <GLFW/glfw3.h>
#include <GL/gl.h>

class GameWorld : GameObject {
private:
  GLFWwindow * window;
  GameAircraft * aircraft;

  void prepareProjection(void) const;
public:
  GameWorld(GLFWwindow * window);
  ~GameWorld(void);

  void draw(void) const;
  void mainWorld(void) const;

  void turn(void);
  void turnLeft(void);
  void turnRight(void);
  void turnFire(void);
};

#endif
