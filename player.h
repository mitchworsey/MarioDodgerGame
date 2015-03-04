#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
class Player : public QGraphicsPixmapItem{
 public:
  Player(QPixmap *pixmap, int nx, int xy);
  void move(int, int);
  void reset();
  int getX();
  int getY();
  bool hit;
 private:
  int x;
  int y;
  int vx;
  int vy;
  int width;
  int height;
  QPixmap *pm;
};
#endif
