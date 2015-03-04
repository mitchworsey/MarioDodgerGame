#ifndef TOOLBAR_H
#define TOOLBAR_H
#include <QToolBar>
#include <QAction>
#include "graphicwindow.h"
#include "formlayout.h"

class ToolBar: public QToolBar{
 Q_OBJECT
 private:
  GraphicWindow *gw;
  FormLayout *fl;
  QAction *start;
  QAction *quit;
  QAction *pause;
  QAction *resume;
  QAction *newG;
 public:
  ToolBar(GraphicWindow *graphwind, FormLayout *formlay);
 public slots:
  void startGame();
  void newGame();
  void quitGame();
  void pauseGame();
  void resumeGame();
};
#endif
