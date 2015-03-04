#include "thing.h"

/** Constructor that inherits from the QGraphicsPixmapItem class
* @param pixmap QPixmap pointer to the pixmap of the Thing
* @param nx Int X location of the Thing
* @param ny Int Y location of the Thing
*/
Thing::Thing(QPixmap *pixmap, int nx, int ny){
 pm = pixmap;
 used = false;
 setPixmap(pm->scaledToHeight(40, Qt::SmoothTransformation));
 x = nx;
 y = ny;
 vx = 0;
 vy = 0;
 width = 40;
 height = 40;
 range = 80;
 setPos(x,y);
}

/** Reverses a Thing's direction of movement*/
void Thing::reverse(){
 vx = -vx;
 vy = -vy;
}

/** Accessor to a Thing's X Location*/
int Thing::getX(){
 return x;
}

/** Accessor to a Thing's Y Location*/
int Thing::getY(){
 return y;
}
