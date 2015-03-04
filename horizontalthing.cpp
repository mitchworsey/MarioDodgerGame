#include "horizontalthing.h"
#include <iostream>

/** Constructor that inherits from the Thing class
* @param pixmap QPixmap pointer to the pixmap of the HorizontalThing
* @param nx Int X location of the HorizontalThing
* @param ny Int Y location of the HorizontalThing
*/
HorizontalThing::HorizontalThing(QPixmap *pixmap, int nx, int ny):Thing(pixmap, nx, ny){
 vx = 1;
}

/** Moves the HorizontalThing horizontally*/
void HorizontalThing::move(){
    setPos(x,y);
    if(range==0 || x < -400 || (x+width) > 400){
     range = 80;
     vx = -vx;
    }
    x += vx;
    range--;
    setPos(x, y);
}
