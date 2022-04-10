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

  newPlayer->xPosition = 7;
  newPlayer->yPosition = 5;

  mvprintw(newPlayer->yPosition, newPlayer->xPosition, "@");
  move(1,0);
  return newPlayer;
}

int screenSetup(){
  initscr();
  printw("Hello, world!");
  noecho();
  refresh();

  return 0;
}

int mapSetup(){
  mvprintw(3, 3, "--------");
  mvprintw(4, 3, "|......|");
  mvprintw(5, 3, "|......|");
  mvprintw(6, 3, "|......|");
  mvprintw(7, 3, "--------");

  mvprintw(9, 3, "-----------");
  mvprintw(10, 3, "|.........|");
  mvprintw(11, 3, "|.........|");
  mvprintw(12, 3, "|.........|");
  mvprintw(13, 3, "-----------");
  
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

  mapSetup();
  user = playerSetup();

  while ((ch = getch()) != 'q') {
    handleInput(ch, user);
  }

  endwin();

  return 0;
}
