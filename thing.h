#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
class Thing : public QGraphicsPixmapItem{
 public:
  Thing(QPixmap *pixmap, int nx, int xy);
  virtual void move() = 0;
  void reverse();
  int getX();
  int getY();
  bool used;
 protected:
  
  int x;
  int y;
  int vx;
  int vy;
  int range;
  int width;
  int height;
  QPixmap *pm;
};
#endif
