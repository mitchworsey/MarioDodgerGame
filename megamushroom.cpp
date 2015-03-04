#include "megamushroom.h"

/** Constructor that inherits from the QGraphicsPixmapItem class
* @param pixmap QPixmap pointer to the pixmap of the MegaMushroom
* @param nx Int X location of the MegaMushroom
* @param ny Int Y location of the MegaMushroom
*/
MegaMushroom::MegaMushroom(QPixmap *pixmap, int nx, int ny){
 pm = pixmap;
 hit = false;
 setPixmap(pm->scaledToHeight(40, Qt::SmoothTransformation));
 x = nx;
 y = ny;
 width = 40;
 height = 40;
 setPos(x,y);
}
