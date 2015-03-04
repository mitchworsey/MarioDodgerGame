#ifndef LOWERRUPPERLTHING_H
#define LOWERRUPPERLTHING_H

#include "thing.h"

class LowerRUpperLThing : public Thing{
 public:
  LowerRUpperLThing(QPixmap *pixmap, int nx, int ny);
  void move();

};
#endif
