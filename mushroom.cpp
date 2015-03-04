#include "mushroom.h"

/** Constructor that inherits from the QGraphicsPixmapItem class
* @param pixmap QPixmap pointer to the pixmap of the Mushroom
* @param nx Int X location of the Mushroom
* @param ny Int Y location of the Mushroom
*/
Mushroom::Mushroom(QPixmap *pixmap, int nx, int ny){
 hit = false;
 pm = pixmap;
 setPixmap(pm->scaledToHeight(40, Qt::SmoothTransformation));
 x = nx;
 y = ny;
 width = 40;
 height = 40;
 setPos(x,y);
}
