#include <raylib.h>
#include <stdbool.h>


#define WIDTH 1280
#define HEIGHT 720

#define CELLSIZE 5

int gameRule(bool board[WIDTH/CELLSIZE][HEIGHT/CELLSIZE], int i, int j)
{
  int neighbor = 0;
    if (i != 0 && board[i-1][j] == true)
      neighbor++;
    if (j != 0 && board[i][j-1] == true)
      neighbor++;
    if ((j != 0 && i != 0) && board[i-1][j-1] == true)
      neighbor++;
    if (i != (WIDTH/CELLSIZE - 1) && board[i+1][j] == true)
      neighbor++;
    if (j != (HEIGHT/CELLSIZE - 1) && board[i][j+1] == true)
      neighbor++;
    if ((i != (WIDTH/CELLSIZE - 1) && j != (HEIGHT/CELLSIZE - 1)) && board[i+1][j+1])
      neighbor++;
    if ((i != 0 && j != (HEIGHT/CELLSIZE - 1)) && board[i-1][j+1])
      neighbor++;
    if ((i != (WIDTH/CELLSIZE - 1) && j != 0) && board[i+1][j-1])
      neighbor++;
  return neighbor;
}

void gameLogic(bool board[WIDTH/CELLSIZE][HEIGHT/CELLSIZE])
{
  int i, j;
  bool tempBoard[WIDTH/CELLSIZE][HEIGHT/CELLSIZE] = {false};

  for (i = 0; i < WIDTH/CELLSIZE; i++) {
    for (j = 0; j < HEIGHT/CELLSIZE; j++) {
      int neighbor = gameRule(board, i, j);

      if (neighbor == 3)
        tempBoard[i][j] = true;
      else if (neighbor == 2)
        tempBoard[i][j] = board[i][j];
      else if (neighbor < 2 || neighbor > 3)
        tempBoard[i][j] = false;
    }
  }
  
  for (i = 0; i < WIDTH/CELLSIZE; i++) {
    for (j = 0; j < HEIGHT/CELLSIZE; j++) {
      board[i][j] = tempBoard[i][j];
    }
  }
}

int main()
{
  InitWindow(WIDTH, HEIGHT, "Game of Life");
  SetTargetFPS(10);

  bool board[WIDTH/CELLSIZE][HEIGHT/CELLSIZE] = {false};
  int i, j;

  // v ADD MODULES HERE v
  board[1][0] = true;
  board[2][1] = true;
  board[0][2] = true;
  board[1][2] = true;
  board[2][2] = true;

  // ^ ADD MODULES HERE ^

  while(!WindowShouldClose())
  {
    gameLogic(board);
    BeginDrawing();
      ClearBackground(BLACK);
      for (i = 0; i < WIDTH/CELLSIZE; i++) {
        for (j = 0; j < HEIGHT/CELLSIZE; j++) {
          if (board[i][j] == true)
            DrawRectangle(CELLSIZE*i, CELLSIZE*j, CELLSIZE, CELLSIZE, WHITE);
        }
      }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}