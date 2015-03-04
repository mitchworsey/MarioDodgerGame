#include "toolbar.h"
/** Constructor of the ToolBar given many different necessary parameters
 * @param graphwind GraphicWindow pointer to the board
 * @param formlay Formlayout pointer to the QLineEdit's
 */
ToolBar::ToolBar(GraphicWindow *graphwind, FormLayout *formlay){
 gw = graphwind;
 fl = formlay;
 start = new QAction("Start Game", this);
 pause = new QAction("Pause Game", this);
 resume = new QAction("Resume Game", this);
 quit = new QAction("Quit Game", this);
 newG = new QAction("New Game", this);
 addAction(start);
 addAction(pause);
 addAction(resume); 
 addAction(quit);
 addAction(newG);
 connect(newG, SIGNAL(triggered()), this, SLOT(newGame())); 
 connect(start, SIGNAL(triggered()), this, SLOT(startGame()));
 connect(pause, SIGNAL(triggered()), this, SLOT(pauseGame()));
 connect(resume, SIGNAL(triggered()), this, SLOT(resumeGame()));
 connect(quit, SIGNAL(triggered()), this, SLOT(quitGame()));
}

/** Calls GraphicWindow's 'startGame()' after the Start Game Button is pressed*/
void ToolBar::startGame(){
 if(fl->getName().find(" ")!=std::string::npos){
  fl->setName();
  return;
 }
 if(fl->getName()!=""){
  gw->startGame();
 }
}

/** Calls GraphicWindow's 'newGame()' after the New Game Button is pressed*/
void ToolBar::newGame(){
 gw->newGame();
}

/** Closes the program when the Quit Game button is pressed*/
void ToolBar::quitGame(){
 exit(0);
}

/** Calls GraphicWindow's 'pauseGame()' after the Pause Game Button is pressed*/
void ToolBar::pauseGame(){
 gw->pauseGame();
}

/** Calls GraphicWindow's 'resumeGame()' after the Resume Game Button is pressed*/
void ToolBar::resumeGame(){
 gw->resumeGame();
}
