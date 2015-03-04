#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
class Background : public QGraphicsPixmapItem{
 public:
  Background(QPixmap *pixmap, int nx, int xy);
 private:
  int x;
  int y;
  int width;
  int height;
  QPixmap *pm;
};
#endif
