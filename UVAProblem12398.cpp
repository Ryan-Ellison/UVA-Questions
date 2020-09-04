

#include <iostream>
#include <array>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::array;

const int LENGTH = 3;
int board[LENGTH][LENGTH] = { 0 };

void uva12398();

//ASSUMING SQUARE ARRAY
void addAdjacent(string moves);

void modBoard(int mod);

void printBoard();

void resetBoard();


int main()
{
	uva12398();
}

void uva12398()
{
	int cases;
	cout << "How many cases do you want to run? \n";
	cin >> cases;
	string moves;
	for (int i = 0; i < cases; i++)
	{
		cout << "\nWhat is your move? \n";
		cin >> moves;
		addAdjacent(moves);
		modBoard(10);
		printBoard();
		resetBoard();
	}
}

void addAdjacent(string moves)
{
	while (moves.length() != 0) {
		int pos = (int)(moves.at(0)) - 97;
		moves = moves.substr(1);
		board[(pos / LENGTH)][pos % LENGTH]++;
		if (pos / LENGTH > 0)
			board[(pos / LENGTH) - 1][pos % LENGTH]++;

		if (pos / LENGTH < LENGTH - 1)
			board[(pos / LENGTH) + 1][pos % LENGTH]++;

		if (pos % LENGTH != 0)
			board[pos / LENGTH][(pos - 1) % LENGTH]++;

		if ((pos % LENGTH) != (LENGTH - 1))
			board[pos / LENGTH][(pos + 1) % LENGTH]++;
	}

}

void modBoard(int mod)
{
	for (int i = 0; i < LENGTH * LENGTH; i++) {
		board[i / LENGTH][i % LENGTH] %= mod;
	}
}

void printBoard()
{
	for (int i = 0; i < LENGTH * LENGTH; i++) {
		if (i % LENGTH == 0)
			cout << "\n";
		cout << board[i / LENGTH][i % LENGTH] << " ";
	}
}

void resetBoard()
{
	for (int i = 0; i < LENGTH * LENGTH; i++) {
		board[i / LENGTH][i % LENGTH] = 0;
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

