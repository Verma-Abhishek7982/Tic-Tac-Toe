#include <iostream>
#include <stdlib.h>
using namespace std;
int row, col;
char turn = 'X';
bool draw = false;
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void
display_board ()
{
  system ("clear");
  cout << "\n\t TICK CROSS GAME" << endl;
  cout << "\n\t PLAYER1 [X] \n\t PLAYER2 [0]\n\n";
  cout << "\t     |     |     \n";
  cout << "\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " <<
	board[0][2] << "  \n";
  cout << "\t_____|_____|_____\n";
  cout << "\t     |     |     \n";
  cout << "\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " <<
	board[1][2] << "  \n";
  cout << "\t_____|_____|_____\n";
  cout << "\t     |     |     \n";
  cout << "\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " <<
	board[2][2] << "  \n";
  cout << "\t     |     |     \n";
}

void
player_turn ()
{
  int choice;

  if (turn == 'X')
	cout << "\n\t PLAYER1 [X] turn:";

  if (turn == '0')
	cout << "\n\t PLAYER2 [0] turn:";
  cin >> choice;

  switch (choice)
	{
	case 1:
	  row = 0;
	  col = 0;
	  break;
	case 2:
	  row = 0;
	  col = 1;
	  break;
	case 3:
	  row = 0;
	  col = 2;
	  break;
	case 4:
	  row = 1;
	  col = 0;
	  break;
	case 5:
	  row = 1;
	  col = 1;
	  break;
	case 6:
	  row = 1;
	  col = 2;
	  break;
	case 7:
	  row = 2;
	  col = 0;
	  break;
	case 8:
	  row = 2;
	  col = 1;
	  break;
	case 9:
	  row = 2;
	  col = 2;
	  break;

	default:
	  cout << "Invalid Choice\n";
	  break;
	}
  if (turn == 'X' && board[row][col] != 'X' && board[row][col] != '0')
	{
	  board[row][col] = 'X';
	  turn = '0';
	}
  else if (turn == '0' && board[row][col] != 'X' && board[row][col] != '0')
	{
	  board[row][col] = '0';
	  turn = 'X';
	}
  else
	{
	  cout << "\tBox Already Fill \n\tPlease Try Again\n";
	  player_turn ();
	}
  display_board ();
}

bool
game_over ()
{
  //case->1 either player 1 or player 2 win
  for (int i = 0; i < 3; i++)
	{
	  if (board[i][0] == board[i][1] && board[i][0] == board[i][2]
		  || board[0][i] == board[1][i] && board[0][i] == board[2][i])
		return false;
	  if (board[0][0] == board[1][1] && board[0][0] == board[2][2]
		  || board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return false;
	}
  //case 2->if there is any box nit filled
  for (int i = 0; i < 3; i++)
	{
	  for (int j = 0; j < 3; j++)
		{
		  if (board[i][j] != 'X' && board[i][j] != '0')
			return true;
		}
	}
  //case->3 game draw
  draw = true;
  return false;
}

int
main ()
{
  while (game_over ())
	{
	  display_board ();
	  player_turn ();
	  game_over ();
	}

  if (turn == 'X' && draw == false)
	cout << "\tPLAYER2 [0] Wins!! Congratulations!\n";

  else if (turn == '0' && draw == false)
	cout << "\tPLAYER1 [X] Wins!! congratulations!\n";

  else
	{
	  cout << "\tGAME DRAW!!\n";
	}

}
