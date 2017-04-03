#include "bullet.hxx"

GameBullet::GameBullet(float hPosition) {
  this->_hPosition = hPosition;
  this->_vPosition = 0;
  this->destroied = false;
}

void GameBullet::draw(void) const {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(this->_hPosition, this->_vPosition, 0);

  glBegin(GL_LINES);
  glColor3f(1.0, 0.8, 0.0);
  glVertex2f(-2, -90);
  glVertex2f(-2, -85);
  glVertex2f(2, -90);
  glVertex2f(2, -85);
  glEnd();
}

void GameBullet::turn(void) {
  this->_vPosition += 1.5f;
  this->destroied = (this->_vPosition >= 185);
}

bool GameBullet::isDestroied(void) const {
  return this->destroied;
}
