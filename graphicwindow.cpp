#include "graphicwindow.h"
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iostream>
/** Constructor that takes in a QListWidget and Formlayout pointer that loads all images
 *@param nqlv QListWidget pointer to print out solution
 *@para formlay FormLayout pointer used to update the score, level, and lives
 */
GraphicWindow::GraphicWindow(QListWidget *nqlv, FormLayout * formlay)  {
    scene = new QGraphicsScene();
    setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    fl = formlay;
    gameover = false;
    int rx, ry;
    randCounter = 0;
    highScoreFile = "highscores.txt";
    
    for(int x = 0; x < 800; x++){
     rx = (rand() % ((WINDOW_MAX_X-40)*2)) - WINDOW_MAX_X+40;
     ry = (rand() % ((WINDOW_MAX_Y-40)*2)) - WINDOW_MAX_Y;
     if(ry < 80 && ry > -80){
      if((rx < 400 && rx > 280) || (rx > -400 && rx < -280)){
       continue;
       x--;
      }
     }
     randXs.push_back(rx);
     randYs.push_back(ry);
    }
    
    
    std::string backgrounds = "background.png";
    const char * backgroundch = backgrounds.c_str();
    QString *backgroundqs = new QString(backgroundch);
    backgroundpm = new QPixmap(*backgroundqs);
    
    std::string background2s = "newbackground2.png";
    const char * background2ch = background2s.c_str();
    QString *background2qs = new QString(background2ch);
    background2pm = new QPixmap(*background2qs);
    
    std::string background3s = "newbackground3.png";
    const char * background3ch = background3s.c_str();
    QString *background3qs = new QString(background3ch);
    background3pm = new QPixmap(*background3qs);
    
    std::string bowsers = "bowser.png";
    const char * bowserch = bowsers.c_str();
    QString *bowserqs = new QString(bowserch);
    bowserpm = new QPixmap(*bowserqs);
    
    std::string donkeykongs = "donkeykong.png";
    const char * donkeykongch = donkeykongs.c_str();
    QString *donkeykongqs = new QString(donkeykongch);
    donkeykongpm = new QPixmap(*donkeykongqs);
    
    std::string bobombs = "newbobomb.png";
    const char * bobombch = bobombs.c_str();
    QString *bobombqs = new QString(bobombch);
    bobombpm = new QPixmap(*bobombqs);
    
    std::string boos = "boo.png";
    const char * booch = boos.c_str();
    QString *booqs = new QString(booch);
    boopm = new QPixmap(*booqs);
    
    std::string goombas = "goomba.png";
    const char * goombach = goombas.c_str();
    QString *goombaqs = new QString(goombach);
    goombapm = new QPixmap(*goombaqs);
    
    std::string marios = "mario.png";
    const char * marioch = marios.c_str();
    QString *marioqs = new QString(marioch);
    mariopm = new QPixmap(*marioqs);
    
    std::string shyguys = "newshyguy.png";
    const char * shyguych = shyguys.c_str();
    QString *shyguyqs = new QString(shyguych);
    shyguypm = new QPixmap(*shyguyqs);
    
    std::string thwomps = "thwomp.png";
    const char * thwompch = thwomps.c_str();
    QString *thwompqs = new QString(thwompch);
    thwomppm = new QPixmap(*thwompqs);    
    
    std::string tubes = "tube.png";
    const char * tubech = tubes.c_str();
    QString *tubeqs = new QString(tubech);
    tubepm = new QPixmap(*tubeqs);
    
    std::string gameovers = "gameover.png";
    const char * gameoverch = gameovers.c_str();
    QString *gameoverqs = new QString(gameoverch);
    gameoverpm = new QPixmap(*gameoverqs);
    
    std::string mushrooms = "mushroom.png";
    const char * mushroomch = mushrooms.c_str();
    QString *mushroomqs = new QString(mushroomch);
    mushroompm = new QPixmap(*mushroomqs);
    
    std::string megamushrooms = "megamushroom.png";
    const char * megamushroomch = megamushrooms.c_str();
    QString *megamushroomqs = new QString(megamushroomch);
    megamushroompm = new QPixmap(*megamushroomqs);
    
    std::string instructionss = "instructions.png";
    const char * instructionsch = instructionss.c_str();
    QString *instructionsqs = new QString(instructionsch);
    instructionspm = new QPixmap(*instructionsqs);
    
    levelTime = new QTimer(this);
    levelTime->setInterval(1000);
    connect(levelTime, SIGNAL(timeout()), this, SLOT(gameTime()));
    
    timer = new QTimer(this);
    
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    startedGame = false;
    
    qlv = nqlv;
    setScene(scene);
    
    g = NULL;
    m = NULL;
    mm = NULL;
    
    i = new Instructions(instructionspm, -400, -280);
    scene->addItem(i);
    
}

/** Slot that increases the time spent on the level*/
void GraphicWindow::gameTime(){
 timeOnLevel++;
}

/** Verifies and adjusts random cordinates if some are too close to eachother
 * @param nx Int of the X Coordinate
 * @param ny Int of the Y Coordinate
 */
void GraphicWindow::checkCords(int &nx, int &ny){

 for(unsigned int z = 0; z< myThings.size(); z++){
  int diffx = myThings[z]->getX() - nx;
  int diffy = myThings[z]->getY() - ny;
  if(diffx < 40 && diffx >-40){
   if(diffy < 40 && diffy >-40){
    if(diffx < 0){
     nx += 40;
     if(nx > 360)
      nx-=120;
    }
    else{
     nx -= 40;
     if(nx < 0)
      nx+=120;
    }
    if(diffy < 0){
     ny += 40;
     if(ny > 240)
      ny-=120;
    }
    else{
     ny -= 40;
     if(ny < 0)
      ny+=120;
    }
    //checkCords(nx, ny);
    break;
   }
  }
 }
}


/** Starts the Game by adding all necessary items to the scene*/
void GraphicWindow::startGame(){
    if(startedGame||gameover)
     return;
    name = fl->getName();
    timerInterval = 40.0;
    timer->setInterval(timerInterval);
    gameover = false;
    lives = 3;
    fl->setLives(lives);
    level = 1;
    fl->setLevel(level);
    score = 0;
    fl->setScore(score);
    
    timeOnLevel = 0;
    
    b = new Background(backgroundpm, -400, -280);
    scene->addItem(b);
    
    t = new Tube(tubepm, 360, 0);
    scene->addItem(t);

    p = new Player(mariopm, -398, 0);
    scene->addItem(p);
    
    for(int a =0; a < 2; a++){
     checkCords(randXs[randCounter], randYs[randCounter]);
     st = new StationaryThing(thwomppm, randXs[randCounter], randYs[randCounter]);
     scene->addItem(st);
     myThings.push_back(st);
     randCounter++;
    }
    
    for(int b = 0; b < 1; b++){
     checkCords(randXs[randCounter], randYs[randCounter]);
     ht = new HorizontalThing(goombapm, randXs[randCounter], randYs[randCounter]);
     scene->addItem(ht);
     myThings.push_back(ht);
     randCounter++;
    }
    
    for(int c = 0; c < 1; c++){
     checkCords(randXs[randCounter], randYs[randCounter]);
     vt = new VerticalThing(bobombpm, randXs[randCounter], randYs[randCounter]);
     scene->addItem(vt);
     myThings.push_back(vt);
     randCounter++;
    }
    
    timer->start();
    levelTime->start();
    startedGame = true;
    readFile();
    fl->setHighScores(highScores, numberScores);
}

/** Pauses the game by stoping timers*/
void GraphicWindow::pauseGame(){
 timer->stop();
 levelTime->stop();
}

/** Resumes the game by restarting timers*/
void GraphicWindow::resumeGame(){
 if(gameover)
  return;
 timer->start();
 levelTime->start();
}

/** Creates a brand new game at anytime during the current game AFTER the startGame function was
  * called once.
  */
void GraphicWindow::newGame(){
 if(startedGame==false)
  return;
 if(g!=NULL)
  scene->removeItem(g);
 if(level>=3 && m->hit==false){
  m->hit = true;
  scene->removeItem(m);
 }
 if(level>=5 && mm->hit==false){
  mm->hit = true;
  scene->removeItem(mm);
 }
 for(unsigned int x = 0; x < myThings.size(); x++){
  //if(myThings[x]!=fbowser&&myThings[x]!=fdk){
  myThings[x]->used = true;
  scene->removeItem(myThings[x]);
  //}
 }
 myThings.clear();
 startedGame = false;
 gameover = false;
 highScores.clear();
 numberScores.clear();
 //fl->setHighScores(highScores, numberScores);
 startGame();
}

/** Moves a player to the given coordinates
  * @param x Int X Coordinate to be moved to
  * @param y Int Y Coordinate to be moved to
  */
void GraphicWindow::movePlayer(int x, int y){
 p->move(x,y);
}

/** Ends the game by adding gameover screen and updating the high scores by sorting them with
  * selection sort
  */
void GraphicWindow::endGame(){
 gameover = true;
 g = new Gameover(gameoverpm, -400, -280);
 scene->addItem(g);
 std::string temps = name;
 highScores.push_back(temps);
 numberScores.push_back(score);
 for(unsigned int x = 0; x < numberScores.size()-1; x++){
  int max  = x;
  for(unsigned int y = x+1; y < numberScores.size(); y++){
   if(numberScores[y] > numberScores[max])
    max = y;
  }
  int temp = numberScores[max];
  numberScores[max] = numberScores[x];
  numberScores[x] = temp;
  std::string temps2 = highScores[max];
  highScores[max] = highScores[x];
  highScores[x] = temps2;
  
 }
 
 fl->setHighScores(highScores, numberScores);
 writeFile();
 
}

/** Reads the high scores file*/
void GraphicWindow::readFile(){
 
 std::string s;
 std::string temps;
 std::stringstream ss;
 int temp;
 fin.open(highScoreFile.c_str());
 if(fin.fail())
  return;
 fin >> s;
 while(!fin.eof()){
  highScores.push_back(s);
  fin >> temp;
  numberScores.push_back(temp);
  fin.ignore(100, '\n');
  fin >> s;
 }
 
 fin.close();
}

/** Updates the high score file*/
void GraphicWindow::writeFile(){
 fout.open(highScoreFile.c_str());
 for(unsigned int x = 0; x < highScores.size(); x++)
  fout << highScores[x] << " " << numberScores[x] << std::endl;
 fout << std::endl;
 fout.close();
}

/** Moves all Things and checks for ALL collisions*/
void GraphicWindow::handleTimer(){
 f++;
 if(f < 40)
  return;
 if(f==40){
  p->hit=false;
 }
  for(unsigned int x = 0; x < myThings.size(); x++)
   myThings[x]->move();
  
  for(unsigned int y = 0; y < myThings.size(); y++){
   if(p->collidesWithItem(myThings[y]) && myThings[y]->used==false){
    p->hit = true;
    lives--;
    score-=5;
    fl->setScore(score);
    fl->setLives(lives);
    timer->stop();
    levelTime->stop();
    if(lives>0)
     restartLevel();
    else{
     endGame();
    }
   }
   if(level>2){
    if(p->collidesWithItem(m)){
     if(m->hit == false){
      score+=10;
      fl->setScore(score);
      m->hit = true;
      scene->removeItem(m);
      lives++;
      fl->setLives(lives);
     }
    }
    else if(p->collidesWithItem(mm)){
     if(mm->hit == false){
      score+=30;
      fl->setScore(score);
      mm->hit = true;
      scene->removeItem(mm);
      lives+=3;
      fl->setLives(lives);
     }
    }
   }
   if(p->collidesWithItem(t)){
    p->hit = true;
    timer->stop();
    levelTime->stop();
    newLevel();
   }
  }
  /*
  
  //Uncomment this block of code for the 'enemies' to collide and bounce off eachother
  //I think having the enemies collide makes the game much harder, so I left that out of
  //the game for now.
  
  for(unsigned int z = 0; z < myThings.size(); z++){
   if(myThings[z]->collidesWithItem(m))
    myThings[z]->reverse();
   if(myThings[z]->collidesWithItem(mm))
    myThings[z]->reverse();
   for(unsigned int zz = 0; zz < myThings.size(); zz++){
    if(zz!=z){
     if(myThings[z]->collidesWithItem(myThings[zz])){
      myThings[z]->reverse();
      break;
     }
    }
   }
  
  }*/
}


/** Sets a level back to its original state*/
void GraphicWindow::restartLevel(){
 f = 0;
 p->reset();
 timeOnLevel = 0;
 timer->start();
 levelTime->start();
}

/** Calculates the Player's score based on the difficulty of the level as well as how fast the 
  * level was completed
  */
void GraphicWindow::calcScore(){
 int temp = 0;
 
 temp += 40 - (3*(timeOnLevel/5));
 if(temp <= 0)
  temp = level*5;
 else
  temp+= level*5;
 
 score += temp;
}


/** Creates a new, more difficult level after completing a previous level and updating the score
*/
void GraphicWindow::newLevel(){
 f = 0;
 level++;
 fl->setLevel(level);
 calcScore();
 fl->setScore(score);
 p->reset();
 
 int a,bb,c,d,e;
 
 if(level >=5){
  for(unsigned int x = 0; x < myThings.size(); x++){
   if(myThings[x]!=fbowser && myThings[x]!=fdk)
    scene->removeItem(myThings[x]);
  }
  scene->removeItem(p);
  scene->removeItem(t);
  scene->removeItem(b);
  b = new Background(background3pm, -400, -280);
  scene->addItem(b);
  scene->addItem(p);
  scene->addItem(t);
  for(unsigned int y = 0; y < myThings.size(); y++){
   if(myThings[y]!=fbowser && myThings[y]!=fdk)
    scene->addItem(myThings[y]);
  }
 }
 else if(level>=3){
  for(unsigned int x = 0; x < myThings.size(); x++){
   if(myThings[x]!=fbowser && myThings[x]!=fdk)
    scene->removeItem(myThings[x]);
  }
  scene->removeItem(p);
  scene->removeItem(t);
  scene->removeItem(b);
  b = new Background(background2pm, -400, -280);
  scene->addItem(b);
  scene->addItem(p);
  scene->addItem(t);
  for(unsigned int y = 0; y < myThings.size(); y++){
   if(myThings[y]!=fbowser && myThings[y]!=fdk)
    scene->addItem(myThings[y]);
  }
  
 }
 
 if(level%2 == 0){
   fbowser = new FollowThing(bowserpm, p, double(randXs[randCounter]), double(randYs[randCounter]));
   scene->addItem(fbowser);
   fbowser->bowser = true;
   myThings.push_back(fbowser);
   randCounter++;
 }
 else if(level > 2 && level%2 != 0){
  fbowser->used = true;
  scene->removeItem(fbowser);
 }
 
 if(level%3==0){
  fdk = new FollowThing(donkeykongpm, p, double(randXs[randCounter]), double(randYs[randCounter]));
  scene->addItem(fdk);
  fdk->bowser = false;
  myThings.push_back(fdk);
  randCounter++;
 }
 else if(level > 3 && level%3 != 0){
  fdk->used = true;
  scene->removeItem(fdk);
 }
 
 
 for(a = 0; a < 1; a++){
     checkCords(randXs[randCounter], randYs[randCounter]);
     st = new StationaryThing(thwomppm, randXs[randCounter], randYs[randCounter]);
     scene->addItem(st);
     myThings.push_back(st);
     randCounter++;
 }
  for(bb = 0; bb < 1; bb++){
     checkCords(randXs[randCounter], randYs[randCounter]);
     ht = new HorizontalThing(goombapm, randXs[randCounter], randYs[randCounter]);
     scene->addItem(ht);
     myThings.push_back(ht);
     randCounter++;
 }
  for(c = 0; c < 1; c++){
     checkCords(randXs[randCounter], randYs[randCounter]);
     vt = new VerticalThing(bobombpm, randXs[randCounter], randYs[randCounter]);
     scene->addItem(vt);
     myThings.push_back(vt);
     randCounter++;
 }
  for(d = 0; d < (1); d++){
     checkCords(randXs[randCounter], randYs[randCounter]);
     llurt = new LowerLUpperRThing(shyguypm, randXs[randCounter], randYs[randCounter]);
     scene->addItem(llurt);
     myThings.push_back(llurt);
     randCounter++;
 }
  for(e = 0; e < (1); e++){
     checkCords(randXs[randCounter], randYs[randCounter]);
     lrult = new LowerRUpperLThing(boopm, randXs[randCounter], randYs[randCounter]);
     scene->addItem(lrult);
     myThings.push_back(lrult);
     randCounter++;
 }
 
 if(level%3 == 0){
  checkCords(randXs[randCounter], randYs[randCounter]);
  m = new Mushroom(mushroompm, randXs[randCounter], randYs[randCounter]);
  scene->addItem(m);
  randCounter++;
 }
 if(level>3 && level%3!=0 && m->hit==false){
  m->hit = true;
  scene->removeItem(m);
 }
 if(level%5 == 0){
  checkCords(randXs[randCounter], randYs[randCounter]);
  mm = new MegaMushroom(megamushroompm, randXs[randCounter], randYs[randCounter]);
  scene->addItem(mm);
  randCounter++;
 }
 if(level>5 && level%5!=0 && mm->hit==false){
  mm->hit = true;
  scene->removeItem(mm);
 }
 
 timeOnLevel = 0;
 timerInterval /= 1.5;
 timer->setInterval(timerInterval);
 timer->start();
 levelTime->start();

}


/** Destructor*/
GraphicWindow::~GraphicWindow()
{
    //timer->stop();
    delete scene;
}


/** Moves the Player based on which Arrow Key is pressed*/
void GraphicWindow::keyPressEvent(QKeyEvent *e){
 if(p->hit)
  return;
 switch ( e->key() ) {
  case Qt::Key_Left:
   movePlayer(-10,0);
   break;
  case Qt::Key_Right:
   movePlayer(10,0);
   break;
  case Qt::Key_Up:
   movePlayer(0,-10);
   break;
  case Qt::Key_Down:
   movePlayer(0,10);
   break;
 }
}


/** Stops moving the Player after the Arrow Key is released*/
void GraphicWindow::keyReleaseEvent(QKeyEvent *e){
 switch ( e->key() ) {
  case Qt::Key_Left:
   movePlayer(0,0);
   break;
  case Qt::Key_Right:
   movePlayer(0,0);
   break;
  case Qt::Key_Up:
   movePlayer(0,0);
   break;
  case Qt::Key_Down:
   movePlayer(0,0);
   break;
 }
}

