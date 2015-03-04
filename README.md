# Game - Programming Assignments Private Repository
### Student Information
  + Name: Mitch Worsey
  + USC Email: worsey@usc.edu
  + USC ID: 8370927291

### Game Information
  + Game Name: Mario Dodger
  + Game Description: Top-down game played with the keyboard where the objective is to make it 
  through the door on the other side of the map.
  + [Game Design Doc](GameDesignDoc.md)


### Compile & Run Instructions
The grader should use the following procedure to compile and run the code:
```shell
#Compile Instructions
qmake -project
qmake
make
#Doxygen Instructions
sudo apt-get install doxygen
doxygen -g config.txt
doxygen config.txt
#Command to run
./game_worsey
```
