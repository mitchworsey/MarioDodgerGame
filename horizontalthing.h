#ifndef HORIZONTALTHING_H
#define HORIZONTALTHING_H

#include "thing.h"

class HorizontalThing : public Thing{
 public:
  HorizontalThing(QPixmap *pixmap, int nx, int ny);
  void move();

};
#endif
