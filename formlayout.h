#ifndef FORMLAYOUT_H
#define FORMLAYOUT_H
#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QTextEdit>
#include <QListWidget>
#include <fstream>
#include <vector>
#include <string>

class FormLayout : public QWidget{
 private:
  QLineEdit *name;
  QLineEdit *lives;
  QLineEdit *score;
  QLineEdit *level;
  QListWidget *highscores;
  QFormLayout *layout;
 public:
  FormLayout();
  std::string getName();
  void setName();
  void setScore(int);
  void setLives(int);
  void setLevel(int);
  void setHighScores(std::vector<std::string> &scoreList, std::vector<int> &numList);
};
#endif
