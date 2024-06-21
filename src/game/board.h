#pragma once

#define boardsize 32

consteval short getBoardOffset() {

  constexpr auto getBoardOffset = [](auto &getBoardOffset, short num) -> short {
    if (num == 0)
      return 0;

    return 1 + getBoardOffset(getBoardOffset, num / 10);
  };

  return getBoardOffset(getBoardOffset, boardsize);
}

class board {

public:
  board();

  void printBoard();

  void update();

private:
  short checkSurrounding(const int row, const int column);
  char gameBoard[boardsize + 5][boardsize + 5];
  char swapBoard[boardsize + 5][boardsize + 5];
};
