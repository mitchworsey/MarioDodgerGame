#include "stationarything.h"

/** Constructor that inherits from the Thing class
* @param pixmap QPixmap pointer to the pixmap of the StationaryThing
* @param nx Int X location of the StartionaryThing
* @param ny Int Y location of the StationaryThing
*/
StationaryThing::StationaryThing(QPixmap *pixmap, int nx, int ny):Thing(pixmap, nx, ny){
}

/** Doesn't move anything, but is needed to comile*/
void StationaryThing::move(){}
