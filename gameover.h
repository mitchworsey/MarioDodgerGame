#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
class Gameover : public QGraphicsPixmapItem{
 public:
  Gameover(QPixmap *pixmap, int nx, int xy);
 private:
  int x;
  int y;
  int width;
  int height;
  QPixmap *pm;
};
#endif
