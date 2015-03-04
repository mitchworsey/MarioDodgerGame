#ifndef FOLLOWTHING_H
#define FOLLOWTHING_H

#include "thing.h"
#include "player.h"

class FollowThing : public Thing{
 public:
  FollowThing(QPixmap *pixmap, Player *np, double nx, double ny);
  void move();
  bool bowser;
 private:
  Player* p;
  double x;
  double y;
  double vx;
  double vy;
  

};
#endif
