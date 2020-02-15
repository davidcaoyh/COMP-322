#include "A1.h"
#include <iostream>
using namespace std;
int main() {
	greetAndInstruct();
	char board[27];
	for (int i = 0; i < 27; i++) {
		board[i] = ' ';
	}
	char input;
	cin >> input;
	while (input != 'y' && input != 'n') {
		cout << "Invalid, enter again" << endl;
		cin >> input;
	}
	if (input == 'n') {
		exit(0);
	}
	displayBoard(board);
	while (checkWinner(board) == false && checkTie(board) == false) {
		int in;
		cin >> in;
		while (checkIfLegal(in, board) == false) {
			cin >> in;
		}
		cout << "board" << endl;
		displayBoard(board);

		if (checkTie(board)) {
			cout << "tie" << endl;
			exit(0);
		}
		if (checkWinner(board)) {
			cout << "Player wins" << endl;
			exit(0);
		}
		computerMove(board);
		cout << "board:" << endl;
		displayBoard(board);
		if (checkTie(board)) {
			cout << "tie" << endl;
			exit(0);
		}
		if (checkWinner(board)) {
			cout << "ai wins" << endl;
			exit(0);
		}


	}
}