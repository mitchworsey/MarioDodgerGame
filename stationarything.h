#ifndef STATIONARYTHING_H
#define STATIONARYTHING_H

#include "thing.h"

class StationaryThing : public Thing{
 public:
  StationaryThing(QPixmap *pixmap, int nx, int ny);
  void move();
};
#endif
