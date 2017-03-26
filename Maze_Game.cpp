#include <iostream> // Starts the preprocessor command including the contents of iostream
using namespace std; // This eliminates the need to write std::cout so it can just be cout

// Function for printing the main menu
void printMenu()
{
	cout << "=========================================\n"
		"\t \tMaze Game \n"
		"=========================================\n"
		"Solve in as little steps as possible\n\n\n"

		"Controls\n"
		"--------------\n\n"
		"U = Up \n"
		"D = Down \n"
		"L = Left \n"
		"R = Right \n"
		"Q = Quit Game (Boo Quitter!)\n\n\n";
}

// Function for showing the Maze Map
void print(char maze[][42])
{
		for (int i = 0; i < 41; ++i)
	{
		for (int j = 0; j < 42; ++j)
		{
			cout << maze[i][j];
		}
		cout << endl;
	}
}

// Function for Player's movement through the maze
int main()
{

// Calls bacj to print the main menu
printMenu();

// 2D Array of Maze map
char maze[][42] = {
{ "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" },
{ "|@|     |   |   |         |           | |" },
{ "+ +-+-+ +-+ + + + + +-+-+-+ + + +-+-+ + +" },
{ "|   |     |   |   |         |   |   | | |" },
{ "+-+ + + + + +-+-+-+-+-+-+-+-+-+-+-+ + + +" },
{ "|   | | | | |           |     |       | |" },
{ "+ +-+ +-+ + + +-+-+-+-+ + +-+ + +-+-+ + +" },
{ "| |     |   | |     | | | | |   |   |   |" },
{ "+ + +-+ + +-+ +-+ + + + + + +-+-+ +-+-+-+" },
{ "|   |   |   |   | |     |             | |" },
{ "+-+-+ +-+-+-+-+ +-+-+ +-+-+ +-+-+ +-+ + +" },
{ "|   |   |       |   |     | |   |   | | |" },
{ "+ + +-+ + +-+-+-+ + +-+ + +-+ + +-+ + + +" },
{ "| |     |   |     | |   |   | |     | | |" },
{ "+ +-+-+-+-+ + +-+-+ + +-+-+ + +-+-+-+ + +" },
{ "|       |   | |   | | |   |   |     |   |" },
{ "+-+ +-+-+ +-+ + + + +-+ + +-+ +-+-+ +-+ +" },
{ "|   |   |   |   | | |   |   | |     | | |" },
{ "+ +-+ + +-+ +-+ + + + +-+-+ + + + +-+ + +" },
{ "|   | |   |   | | |   |   | | | | | | | |" },
{ "+-+ +-+ + +-+ +-+ + +-+ +-+ +-+ + + + + +" },
{ "|   |   |   |   | |   | |       |   |   |" },
{ "+ +-+ +-+-+-+-+ + + + + + + + +-+-+-+-+-+" },
{ "| |   | |     | | | | |   | |       |   |" },
{ "+ + +-+ + +-+ + + + + + +-+ + +-+-+ + +-+" },
{ "| | |   |   |     | | | |   |     | |   |" },
{ "+ + + + +-+ +-+-+-+-+ +-+ +-+-+-+-+ +-+ +" },
{ "| | | |     |   |   | |   |       | |   |" },
{ "+ + + +-+-+-+ +-+ + + + + + +-+-+ + + +-+" },
{ "|   |       |     |   | |       |   |   |" },
{ "+-+ +-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+ +" },
{ "|   |   | |     |         |       |   | |" },
{ "+ +-+ + + + +-+ +-+ +-+-+ + +-+-+ +-+ + +" },
{ "| | | |     | |     | |   | |   |   |   |" },
{ "+ + + +-+-+-+ +-+-+-+ + +-+ +-+ +-+ + + +" },
{ "|   | |   |     |   |   |     | | |   | |" },
{ "+ +-+ + +-+ +-+ +-+ +-+-+-+ + + + +-+-+ +" },
{ "| |   |     |   |   |   |   | | |     | |" },
{ "+ + +-+ +-+-+ +-+ + + + + +-+ + + +-+ + +" },
{ "| |         |     |   |     |   |   |  X|" },
{ "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" },
};
	// Declares where the player's starting position is 
	int row = 1; 
	int col = 1;

	// Keeps track of the number of steps it takes to get to the goal
	int counter = 0;

	// Boolean statement showing that the game is running the loop until the player quits or reaches the goal
	bool GameOver = false;
	while(!GameOver)
	{
		print(maze); // Calls back to the function and prints the maze map

		char PlayerMove = ' '; // Moves the player by one space
		cout << "\nMove: "; // Promts the player to move

		// While statment to continue to prompt player to move until the goal is reached
		while(PlayerMove != 'u' && PlayerMove != 'd' && PlayerMove != 'l' && PlayerMove != 'r' && PlayerMove != 'q')
		{
			cin >> PlayerMove;
		}

		if (PlayerMove == 'u')
		{
			if (maze[row - 1][col] == ' ')
			{
				maze[row][col] = ' ';
				row--;
				maze[row][col] = '@';
				counter++;
			}
			else if (maze[row - 1][col] == '#')
			{
				GameOver = true;
			}
		}
		else if (PlayerMove == 'd')
		{
			if (maze[row + 1][col] == ' ')
			{
				maze[row][col] = ' ';
				row++;
				maze[row][col] = '@';
				counter++;
			}
			else if (maze[row + 1][col] == '#')
			{
				GameOver = true;
			}
		}
		else if (PlayerMove == 'l')
		{
			if (maze[row][col - 1] == ' ')
			{
				maze[row][col] = ' ';
				col--;
				maze[row][col] = '@';
				counter++;
			}
			else if (maze[row][col - 1] == '#')
			{
				GameOver = true;
			}
		}
		else if (PlayerMove == 'r')
		{
			if (maze[row][col + 1] == ' ')
			{
				maze[row][col] = ' ';
				col++;
				maze[row][col] = '@';
				counter++;
			}
			else if (maze[row][col + 1] == '#') // If the player finds the goal then the game ends
			{
				cout << "Congratulation! You win! You reached the goal in" << " " << counter << " " << "steps!";
				GameOver = true;
			}
		}
		else if (PlayerMove == 'q') // Quits the game
		{
			GameOver = true;
		}
		else
		{
			cout << "Invalid Input." << endl;
		}
	}

	return 0;
}

/* 	==================================================[ BUG NOTES ]========================================================
1. Couldn't get maze map to print. Accidentally put number of rows/cols in brackets for i and j.
2. Player started in inccoreect position. Changed the starting coordinates to accomodate for the extra number.
========================================================================================================================== */
