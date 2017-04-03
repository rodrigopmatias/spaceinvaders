#ifndef __GAME_AIRCRAFT_H__
#define __GAME_AIRCRAFT_H__

#include "object.hxx"
#include "bullet/bullet.hxx"

#define AIRCRAFT_MAX_BULLETS            5

#include <iostream>
#include <GL/gl.h>

class GameAircraft : public GameObject {
private:
  float dH = 0.0f;
  float _hPosition = 0.0f;

  GameBullet * bullets[AIRCRAFT_MAX_BULLETS];
public:
  GameAircraft(void);

  void draw(void) const;

  void turn(void);
  void moveLeft(void);
  void moveRight(void);
  void fire(void);
};

#endif
