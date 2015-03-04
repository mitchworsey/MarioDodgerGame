#include "tube.h"

/** Constructor that inherits from the QGraphicsPixmapItem class
* @param pixmap QPixmap pointer to the pixmap of the Tube
* @param nx Int X location of the Tube
* @param ny Int Y location of the Tube
*/
Tube::Tube(QPixmap *pixmap, int nx, int ny){
 pm = pixmap;
 setPixmap(pm->scaledToHeight(40, Qt::SmoothTransformation));
 x = nx;
 y = ny;
 width = 40;
 height = 40;
 setPos(x,y);
}
