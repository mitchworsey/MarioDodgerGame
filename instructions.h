#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
class Instructions : public QGraphicsPixmapItem{
 public:
  Instructions(QPixmap *pixmap, int nx, int xy);
 private:
  int x;
  int y;
  int width;
  int height;
  QPixmap *pm;
};
#endif
