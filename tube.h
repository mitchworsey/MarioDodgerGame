#ifndef TUBE_H
#define TUBE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
class Tube : public QGraphicsPixmapItem{
 public:
  Tube(QPixmap *pixmap, int nx, int xy);
 private:
  int x;
  int y;
  int width;
  int height;
  QPixmap *pm;
};
#endif
