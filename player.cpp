#include "player.h"

/** Constructor that inherits from the QGraphicsPixmapItem class
* @param pixmap QPixmap pointer to the pixmap of the Player
* @param nx Int X location of the Player
* @param ny Int Y location of the Player
*/
Player::Player(QPixmap *pixmap, int nx, int ny){
 pm = pixmap;
 hit = false;
 setPixmap(pm->scaledToHeight(40, Qt::SmoothTransformation));
 x = nx;
 y = ny;
 width = 40;
 height = 40;
 setPos(x,y);
}

/** Accessor to X Location
*/
int Player::getX(){
 return x;
}

/** Accessor to Y Location
*/
int Player::getY(){
 return y;
}

/** Moves the Player back to it's original location
*/
void Player::reset(){
 setPos(x,y);
 x = -398;
 y = 0;
 setPos(x,y);
}

/** Moves the player to the specified location
* @param nx Int X location to be moved to
* @param ny Int Y location to be moved to
*/
void Player::move(int nx, int ny){
 setPos(x,y);
 vx = nx;
 vy = ny;
 if(x>=-400 && y >=-280 && (x+width) <= 400 && (y+height) <=240){
  x+=vx;
  y+=vy;
 }
 if(x<-400)
  x=-399;
 if(y<-280)
  y=-279;
 if((x+width)>400)
  x=359;
 if((y+height)>240)
  y=199;
 setPos(x, y);
}
