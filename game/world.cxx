#include "world.hxx"

GameWorld::~GameWorld(void) {
  if(this->aircraft)
    delete this->aircraft;
}

void GameWorld::turnLeft(void) {
  this->aircraft->moveLeft();
}

void GameWorld::turnRight(void) {
  this->aircraft->moveRight();
}

void GameWorld::turnFire(void) {
  this->aircraft->fire();
}

GameWorld::GameWorld(GLFWwindow * window) {
  this->aircraft = new GameAircraft();
}

void GameWorld::mainWorld(void) const {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glBegin(GL_LINES);
  glColor3f(1.0, 1.0, 0.0);
  glVertex2f(-99, 99);
  glVertex2f(-99, -99);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1.0, 1.0, 0.0);
  glVertex2f(-99, -99);
  glVertex2f(99, -99);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1.0, 1.0, 0.0);
  glVertex2f(99, -99);
  glVertex2f(99, 99);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1.0, 1.0, 0.0);
  glVertex2f(99, 99);
  glVertex2f(-99, 99);
  glEnd();
}

void GameWorld::draw(void) const {
  this->prepareProjection();
  this->mainWorld();

  this->prepareProjection();
  this->aircraft->draw();
}

void GameWorld::prepareProjection(void) const {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-100, 100, -100, 100, -100, 100);
}

void GameWorld::turn(void) {
  this->aircraft->turn();
}
