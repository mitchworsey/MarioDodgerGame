#ifndef VERTICALTHING_H
#define VERTICALTHING_H

#include "thing.h"

class VerticalThing : public Thing{
 public:
  VerticalThing(QPixmap *pixmap, int nx, int ny);
  void move();

};
#endif
