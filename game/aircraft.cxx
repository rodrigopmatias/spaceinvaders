#include "aircraft.hxx"

GameAircraft::GameAircraft(void) {
  for(char i = 0; i < AIRCRAFT_MAX_BULLETS; i++)
    this->bullets[i] = 0;
}

GameAircraft::~GameAircraft(void) {
  for(char i = 0; i < AIRCRAFT_MAX_BULLETS; i++)
    if(this->bullets[i])
      delete this->bullets[i];
}

void GameAircraft::turn(void) {
  this->dH = (this->dH < 3.0f ? this->dH : 3.0f);
  this->dH = (this->dH > -3.0f ? this->dH : -3.0f);

  this->_hPosition += this->dH;
  if(this->_hPosition > 88.0f) {
    this->dH = 0;
    this->_hPosition = 88.0f;
  }
  else if(this->_hPosition < -88.0f) {
    this->dH = 0;
    this->_hPosition = -88.0f;
  }

  for(char i = 0; i < AIRCRAFT_MAX_BULLETS; i++)
    if(this->bullets[i] && !this->bullets[i]->isDestroied())
      this->bullets[i]->turn();
    else if(this->bullets[i] && this->bullets[i]->isDestroied()) {
      delete this->bullets[i];
      this->bullets[i] = 0;
    }
}

void GameAircraft::draw(void) const {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(this->_hPosition, 0, 0);

  glBegin(GL_LINES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(-8, -87);
  glVertex2f(8, -87);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(8, -87);
  glVertex2f(8, -96);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(8, -96);
  glVertex2f(-8, -96);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(-8, -96);
  glVertex2f(-8, -87);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.4, 0.0, 0.0);
  glVertex2f(-7, -88);
  glVertex2f(7, -88);
  glVertex2f(7, -95);
  glVertex2f(-7, -95);
  glEnd();

  for(char i = 0; i < AIRCRAFT_MAX_BULLETS; i++) {
    GameBullet * bullet = this->bullets[i];

    if(bullet && !bullet->isDestroied())
      bullet->draw();
  }
}

void GameAircraft::moveLeft(void) {
  this->dH -= 1.0;
  std::cout << "Aircraft turn LEFT(" << this->dH << ")" << std::endl;
}

void GameAircraft::moveRight(void) {
  this->dH += 1.0;
  std::cout << "Aircraft turn RIGHT(" << this->dH << ")" << std::endl;
}

void GameAircraft::fire(void) {
  for(char i = 0; i < AIRCRAFT_MAX_BULLETS; i++) {
    if(!this->bullets[i]) {
      this->bullets[i] = new GameBullet(this->_hPosition);
      break;
    }
  }
}
