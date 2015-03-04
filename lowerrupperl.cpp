#include "lowerrupperl.h"

/** Constructor that inherits from the Thing class
* @param pixmap QPixmap pointer to the pixmap of the LowerRUpperLThing
* @param nx Int X location of the LowerRUpperLThing
* @param ny Int Y location of the LowerRUpperLThing
*/
LowerRUpperLThing::LowerRUpperLThing(QPixmap *pixmap, int nx, int ny):Thing(pixmap, nx, ny){
 vx = -1;
 vy = -1;
}

/** Moves the LowerRUpperLThing in a diagonal direction
*/
void LowerRUpperLThing::move(){
    setPos(x,y);
    if(range==0 || x < -400 || y < -280 || (x+width)>400 || (y+height)>240){
     range = 80;
     vx = -vx;
     vy = -vy;
    }    
    x += vx;
    y += vy;
    range--;
    setPos(x, y);
}
