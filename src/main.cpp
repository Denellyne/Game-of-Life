#include "game/board.h"

int main(int argc, char *argv[]) {

  board game;
  while (1) {
    game.update();
    game.printBoard();
  }

  return 0;
}
