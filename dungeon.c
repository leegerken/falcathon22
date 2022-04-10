#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>

typedef struct Player{
  int xPosition;
  int yPosition;
  int health;
} Player;

int playerMove(int y, int x, Player * user); 

  Player * playerSetup(){
  Player * newPlayer;
  newPlayer = malloc(sizeof(Player));

  newPlayer->xPosition = 4;
  newPlayer->yPosition = 2;

  mvprintw(newPlayer->yPosition, newPlayer->xPosition, "@");
  move(1,0);
  return newPlayer;
}

int screenSetup(){
  initscr();
  noecho();
  refresh();
  curs_set(0);

  return 0;
}

int titleSetup(){

  mvprintw(0, 10, "Falcathon 2022");
  mvprintw(4, 8, "DUNGEON");
  mvprintw(6, 8, "Press z");
  mvprintw(7, 1, "Version 0.1");
  while (getch() != 'z') {
  }
 
  clear();
  return 0;
}

int mapSetup(){
  
  mvprintw(0, 2, "--------  ------------");
  mvprintw(1, 2, "|......|  |..........|");
  mvprintw(2, 2, "|....................|");
  mvprintw(3, 2, "|......|  |..........|");
  mvprintw(4, 2, "--------  ------------");

  mvprintw(6,  1,  "-----------------------");
  mvprintw(7,  1,  "Life: 10");
  mvprintw(7, 18, "(q)uit");
  
  return 0;
}

int handleInput(int input, Player * user){
  
  switch(input) {
    case 'w':
    case 'W':
      playerMove(user->yPosition - 1, user->xPosition, user);
      break;

    case 's':
    case 'S':
      playerMove(user->yPosition + 1, user->xPosition, user);
      break;

    case 'a':
    case 'A':
      playerMove(user->yPosition, user->xPosition - 1, user);
      break;
    case 'd':
    case 'D':
      playerMove(user->yPosition, user->xPosition + 1, user);
      break;
   }
  return 0;
}

int playerMove(int y, int x, Player * user) {
  mvprintw(user->yPosition, user->xPosition, ".");

  user->yPosition = y;
  user->xPosition = x;

  mvprintw(user->yPosition, user->xPosition, "@");
  move(1,0);

  return 0;
}

int main() {
  Player * user;
  int ch;
  screenSetup();
  
  titleSetup();

  mapSetup();
  user = playerSetup();

  while ((ch = getch()) != 'q') {
    handleInput(ch, user);
  }

  endwin();

  return 0;
}
