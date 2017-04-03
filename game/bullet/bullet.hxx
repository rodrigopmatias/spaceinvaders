#ifndef __GAME_ENEMY_H__
#define __GAME_ENEMY_H__

#include "../object.hxx"

#include <GL/gl.h>

class GameBullet : GameObject {
protected:
  float _hPosition;
  float _vPosition;

  bool destroied;
public:
  GameBullet(float hPosition);

  void turn(void);
  void draw(void) const;

  bool isDestroied(void) const;
};

#endif
