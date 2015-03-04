#ifndef MEGAMUSHROOM_H
#define MEGAMUSHROOM_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
class MegaMushroom : public QGraphicsPixmapItem{
 public:
  MegaMushroom(QPixmap *pixmap, int nx, int xy);
  bool hit;
 private:
  int x;
  int y;
  int width;
  int height;
  QPixmap *pm;
};
#endif
