#ifndef LOWERLUPPERRYTHING_H
#define LOWERLUPPERRTHING_H

#include "thing.h"

class LowerLUpperRThing : public Thing{
 public:
  LowerLUpperRThing(QPixmap *pixmap, int nx, int ny);
  void move();

};
#endif
