//Ciaran McErlean
//10/4/22
//TicTacToe Project
//Period 6

#include<iostream>
#include<cstring>
using namespace std;

char square[10] = {'0','1','2','3','4','5','6','7','8','9'}; //Array for the board 

int checkwin();
void board();

void clearboard() //Clears the board if the user doesn't want to play again 
{
  for (int i = 0; i < 10; i++) {
    square[i] = '0' + i;
  }
}

int main() {
  int player = 1,i,choice; //ints for player, and player wins  
  int player_1_win = 0;
  int player_2_win = 0;

  char mark;

  char playagain = 'y'; //char for playagain 
  while(playagain == 'y')//while loop to play again if the user wants too
    {
  do
    {//Adds  the marks to each of the boxs, and tells player if it is a invalid move 
      board();
      player=(player%2)?1:2;

      cout << "Player" << player << ", enter a number: ";
      cin >> choice;

	mark = (player == 1) ? 'X' : 'O';

      if (choice == 1 && square[1] == '1')

	square[1] = mark;
      else if (choice == 2 && square[2] == '2')

	square[2] = mark;
      else if (choice == 3 && square[3] == '3')

	square[3] = mark;
      else if (choice == 4 && square[4] == '4')

	square[4] = mark;
      else if (choice == 5 && square[5] == '5')

	square[5] = mark;
      else if (choice == 6 && square[6] == '6')

	square[6] = mark;
      else if (choice == 7 && square[7] == '7')

	square[7] = mark;
      else if (choice == 8 && square[8] == '8')

	square[8] = mark;
      else if (choice == 9 && square[9] == '9')

	square[9] = mark;

      else {
	cout << "Invalid Move";

	player--;
	cin.ignore();
	cin.get();
      }
      i = checkwin();
      cout << i;

      player++;
    }
 while ( i == -1); //Prints who wins and adds it to tally of win for each person 
  board();
  if (i == 1)
    cout <<"==>\aPlayer"<<--player<<" win ";
  if (player == 1)
  ++player_1_win;
  else
    ++player_2_win;
  if (i == 0)
    cout <<"==>\aGame draw";

  cout << "\n\nWanna play again(y/n)?:"; //Asks user if they want to play again
  cin >> playagain;
  cout << endl;

  if (playagain == 'y') //All the options for play again
    {
      cout << "You choice to play again\n\n";
      clearboard();
      cout << "player 1 has won " << player_1_win << " times" << endl;
      cout << "Player 2 has won " << player_2_win << " times" << endl;
    }
  else if (playagain == 'n')
    {
      cout << "You choice not to play again\n\n";
    }
  else
    {
      cout << " You didn't put an valid character so it will act like an n\n\n";
      
    }

  for(int c=0; c < 40; c++)
    {
      cout << "****";
    }
  cout << endl;
    }

    

  
  
  return 0;
}





int checkwin() //checks the board for a win condtion 
{
  if (square[1] == square[2] && square[2] == square[3])

    return 1;
  else if (square[4] == square[5] && square[5] == square[6])

    return 1;
  else if (square[7] == square[8] && square[8] == square[9])

    return 1;
  else if (square[1] == square[4] && square[4] == square[7])

    return 1;
  else if (square[2] == square[5] && square[5] == square[8])

    return 1;
  else if (square[3] == square[6] && square[6] == square[9])

    return 1;
  else if (square[1] == square[5] && square[5] == square[9])

    return 1;
  else if (square[3] == square[5] && square[5] == square[7])

    return 1;
  else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
	   && square[4] != '4' && square[5] != '5' && square[6] != '6'
	   && square[7] != '7' && square[8] != '8' && square[9] != '9') //checks for tie 

    return 0;
  else
    return -1;

}

void board() { //The void for the board it's self 
  cout << "\n\n\tTic Tac Toe\n\n";

  cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
  cout << endl;

  cout << "   |   |   " << endl;
  cout << " " << square[1] << " | " << square[2] << " | "  << square[3] << endl;

  cout << "___|___|___" << endl;
  cout << "   |   |   " << endl;

  cout << " "  << square[4] << " | " << square[5] << " | " << square[6] << endl;

  cout << "___|___|___" << endl;
  cout << "   |   |   " << endl;

  cout << " " << square[7] << " | " << square[8] << " | " <<  square[9] << endl;

  cout << "   |   |   " << endl << endl;


}

