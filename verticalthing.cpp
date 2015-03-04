#include "verticalthing.h"

/** Constructor that inherits from the Thing class
* @param pixmap QPixmap pointer to the pixmap of the VerticalThing
* @param nx Int X location of the VerticalThing
* @param ny Int Y location of the VerticalThing
*/
VerticalThing::VerticalThing(QPixmap *pixmap, int nx, int ny):Thing(pixmap, nx, ny){
 vy = 1;
}

/** Moves the VerticalThing
*/
void VerticalThing::move(){
    setPos(x,y);
    if(range==0 || y < -280 || (y+height) > 240){
     range = 80;
     vy = -vy;
    }
    y += vy;
    range--;
    setPos(x, y);
}
