#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QFont>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <cstdlib>
#include <vector>
#include <QLabel>
#include <QString>
#include <QListWidget>
#include <QStringList>
#include <QPixmap>
#include <QKeyEvent>

#include "instructions.h"
#include "followthing.h"
#include "thing.h"
#include "player.h"
#include "stationarything.h"
#include "horizontalthing.h"
#include "verticalthing.h"
#include "lowerlupperr.h"
#include "lowerrupperl.h"
#include "background.h"
#include "tube.h"
#include "gameover.h"
#include "mushroom.h"
#include "megamushroom.h"
#include <fstream>

#include "formlayout.h"

#define WINDOW_MAX_X 400
#define WINDOW_MAX_Y 280

class GraphicWindow : public QGraphicsView {
    Q_OBJECT
    
public:
    explicit GraphicWindow(QListWidget * nqlv, FormLayout *formlay);
    void startGame();
    void pauseGame();
    void resumeGame();
    ~GraphicWindow();
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void movePlayer(int, int);
    void newLevel();
    void calcScore();
    void restartLevel();
    void checkCords(int &, int &);
    void newGame();
    void endGame();
    void readFile();
    void writeFile();
    
private:
    std::ifstream fin;
    std::ofstream fout;
    std::string highScoreFile;
    QGraphicsScene *scene;
    FormLayout *fl;
    std::vector<int> numberScores;
    std::vector<std::string> highScores;
    std::string name;
    QPixmap *backgroundpm;
    QPixmap *background2pm;
    QPixmap *background3pm;
    QPixmap *bowserpm;
    QPixmap *donkeykongpm;
    QPixmap *bobombpm;
    QPixmap *boopm;
    QPixmap *goombapm;
    QPixmap *mariopm;
    QPixmap *shyguypm;
    QPixmap *thwomppm;
    QPixmap *tubepm;
    QPixmap *gameoverpm;
    QPixmap *mushroompm;
    QPixmap *megamushroompm;
    QPixmap *instructionspm;
    Instructions *i;
    Background *b;
    Gameover *g;
    Mushroom *m;
    MegaMushroom *mm;
    FollowThing *fbowser;
    FollowThing *fdk;
    Tube *t;
    Player *p;
    StationaryThing *st;
    HorizontalThing *ht;
    VerticalThing *vt;
    LowerLUpperRThing *llurt;
    LowerRUpperLThing *lrult;
    std::vector<int> randXs;
    std::vector<int> randYs;
    std::vector<Thing *> myThings;
    QListWidget *qlv;
    QTimer *timer;
    QTimer *levelTime;
    bool startedGame;
    bool gameover;
    int randCounter;
    int timeOnLevel;
    int lives;
    int level;
    int score;
    double timerInterval;
    int f;

public slots:
    //void setManhattan();
    //void setOutOfPlace();
    void handleTimer();
    void gameTime();
};

#endif // GRAPHICWINDOW_H
