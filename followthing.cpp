#include "followthing.h"
#include <iostream>

/** Constructor that inherits from the Thing class
* @param pixmap QPixmap pointer to the pixmap of the FollowThing
* @param nx Int X location of the FollowThing
* @param ny Int Y location of the FollowThing
*/
FollowThing::FollowThing(QPixmap *pixmap, Player *np, double nx, double ny):Thing(pixmap, nx, ny){
 p = np;
}

/** Follows the player*/
void FollowThing::move(){
    setPos(x,y);
    //if(x < -400 || y < -280 || (x+width)>400 || (y+height)>240){
     //vx = -vx;
     //vy = -vy;
    //}
    double pcentx = p->getX() +20;
    double pcenty = p->getY() +20;
    double xdiff = pcentx - (x+20);
    double ydiff = pcenty - (y+20);
    if(bowser){
     vx = xdiff/140;
     vy = ydiff/140;
    }
    else{
     vx = xdiff/70;
     vy = ydiff/70;
    }
    x += vx;
    y += vy;
    //if(y < 80 && y > -80){
      if( (x > -400 && x < -280)){
       x-=vx;
       y-=vy;
      }
     //}
    //range--;
    setPos(x, y);
}
