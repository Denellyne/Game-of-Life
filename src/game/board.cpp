#include "board.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

board::board() {
  std::srand(std::time(0));

  for (int i = 0; i < boardsize + 5; i++)
    for (int j = 0; j < boardsize + 5; j++) {
      swapBoard[i][j] = ' ';
      gameBoard[i][j] = ' ';
    }

  for (int i = 1; i <= boardsize; i++) {
    for (int j = 1; j <= boardsize; j++)
      if (rand() % (boardsize >> 2) == 0)
        gameBoard[i][j] = 'o';
      else
        gameBoard[i][j] = ' ';
  }
  // gameBoard[4][3] = 'o';
  // gameBoard[5][4] = 'o';
  // gameBoard[6][2] = 'o';
  // gameBoard[6][3] = 'o';
  // gameBoard[6][4] = 'o';
}

void board::printBoard() {
  system("cls");
  for (int i = 1; i <= boardsize; i++) {
    std::cout << i << ' ';
    for (int j = 1; j <= boardsize; j++)
      std::cout << gameBoard[i][j];
    std::cout << '\n';
  }
}

short board::checkSurrounding(const int row, const int column) {

  return (short)((gameBoard[row - 1][column - 1] == 'o') +
                 (gameBoard[row - 1][column] == 'o') +
                 (gameBoard[row - 1][column + 1] == 'o') +

                 (gameBoard[row][column + 1] == 'o') +
                 (gameBoard[row][column - 1] == 'o') +

                 (gameBoard[row + 1][column - 1] == 'o') +
                 (gameBoard[row + 1][column] == 'o') +
                 (gameBoard[row + 1][column + 1] == 'o'));
}

void board::update() {

  for (int i = 1; i <= boardsize; i++) {
    for (int j = 1; j <= boardsize; j++) {
      switch (checkSurrounding(i, j)) {

      case 0:
        [[fallthrough]];
      case 1:
        swapBoard[i][j] = ' ';
        break;
      case 2:
        if (gameBoard[i][j] == ' ') {
          swapBoard[i][j] = ' ';
          break;
        }
        [[fallthrough]];
      case 3:
        swapBoard[i][j] = 'o';
        break;
      default:
        swapBoard[i][j] = ' ';
        break;
      }
    }
  }

  std::this_thread::sleep_for(std::chrono::milliseconds(300));

  memcpy(&gameBoard[0][0], &swapBoard[0][0],
         (boardsize + 1) * (boardsize + 1) * sizeof(gameBoard[0][0]));
  return;
}
