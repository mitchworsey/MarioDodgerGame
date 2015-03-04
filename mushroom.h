#ifndef MUSHROOM_H
#define MUSHROOM_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
class Mushroom : public QGraphicsPixmapItem{
 public:
  Mushroom(QPixmap *pixmap, int nx, int xy);
  bool hit;
 private:
  int x;
  int y;
  int width;
  int height;
  QPixmap *pm;
};
#endif
