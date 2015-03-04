#include "instructions.h"

/** Constructor that inherits from the QGraphicsPixmapItem class
* @param pixmap QPixmap pointer to the pixmap of the Instructions screen
* @param nx Int X location of the Instructions screen
* @param ny Int Y location of the Instructions screen
*/
Instructions::Instructions(QPixmap *pixmap, int nx, int ny){
 pm = pixmap;
 setPixmap(pm->scaledToWidth(800, Qt::SmoothTransformation));
 x = nx;
 y = ny;
 width = 800;
 height = 560;
 setPos(x,y);
}
