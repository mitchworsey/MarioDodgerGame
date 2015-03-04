#include "formlayout.h"
#include <iostream>
#include <QString>
#include <sstream>
#include <QStringList>


/** Constructor that allocates all QLineEdit's*/
FormLayout::FormLayout(){
 layout = new QFormLayout();
 setLayout(layout);
 
 name = new QLineEdit();
 lives = new QLineEdit();
  lives->setReadOnly(true);
 score = new QLineEdit();
  score->setReadOnly(true);
 level = new QLineEdit();
 level->setReadOnly(true);
 highscores = new QListWidget();
 
 layout->addRow("Name", name);
 layout->addRow("Level", level);
 layout->addRow("Score", score);
 layout->addRow("Lives", lives);
 layout->addRow("High Scores", highscores);
 
}

/** Sets the name QLineEdit
*/
void FormLayout::setName(){
 std::string s = "One word please";
 const char * ch = s.c_str();
 QString *qs = new QString(ch);
 name->setText(*qs);
}

/** Sets the highScores QListWidget
* @param vector<string> scoreList The list of high score names
* @param vector<int> numList The list of high scores
*/
void FormLayout::setHighScores(std::vector<std::string> &scoreList, std::vector<int> &numList){
  highscores->clear();
  QStringList *qsl = new QStringList();
  for(unsigned int x = 0; x < scoreList.size(); x++){
      std::stringstream ss;
      ss << scoreList[x];
      std::string s = ss.str();
      const char * ch = s.c_str();
      QString *qs = new QString(ch);
      
      char * space = " ";
      QString *qspace = new QString(space);
      
      qs->append(qspace);
      
      std::stringstream ss2;
      ss2 << numList[x];
      std::string s2 = ss2.str();
      const char * ch2 = s2.c_str();
      QString *qs2 = new QString(ch2);
      qs->append(qs2);
      qsl->insert(x,*qs);
  }
  highscores->insertItems(0,*qsl);
 
}

/** Accessor to the name input by the user*/
std::string FormLayout::getName(){
 return name->text().toStdString();
}

/** Sets the score QLineEdit
* @param int a The number that will be set to the score
*/
void FormLayout::setScore(int a){
 std::stringstream ss;
 ss << a;
 std::string s = ss.str();
 const char * ch = s.c_str();
 QString *qs = new QString(ch);
 score->setText(*qs);
}

/** Sets the level QLineEdit
* @param int a The number that will be set to the level
*/
void FormLayout::setLevel(int a){
 std::stringstream ss;
 ss << a;
 std::string s = ss.str();
 const char * ch = s.c_str();
 QString *qs = new QString(ch);
 level->setText(*qs);
}

/** Sets the lives QLineEdit
* @param int a The number that will be set to the lives
*/
void FormLayout::setLives(int a){
 std::stringstream ss;
 ss << a;
 std::string s = ss.str();
 const char * ch = s.c_str();
 QString *qs = new QString(ch);
 lives->setText(*qs);
}

