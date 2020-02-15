#include<iostream>
#include "A1.h"
using namespace std;
void greetAndInstruct();
void displayBoard(char board[]);
bool checkIfLegal(int cellNbre, char boardp[]);
bool checkWinner(char board[]);
bool checkTie(char board[]);
void computerMove(char board[]);
/*
void main() {
	char board[27];
	for (int i = 0; i < 27; i++) {
		board[i] = ' ';
	}
	board[2] = 'x';
	board[13] = 'x';
	board[24] = 'x';
	displayBoard(board);

	if (checkWinner(board)) {
		cout << "check" << endl;
	}
	

}
*/


void greetAndInstruct() {
	cout << "Hello and welcome to the Tic - Tac - Toe challenge : Player against Computer." << endl;
	cout << "The board is numbered from 1 to 27 as per the following:" << endl;
	cout << "1 | 2 | 3    10 | 11 | 12      19 | 20 | 21" << endl;
	cout << "------------ ---------------- ----------------" << endl;
	cout << "4 | 5 | 6    13 | 14 | 15      22 | 23 | 24" << endl;
	cout << "------------ ---------------- ----------------" << endl;
	cout << "7 | 8 | 9    16 | 17 | 18      25 | 26 | 27" << endl;
	cout << "Player starts first. Simply input the number of the cell you want to occupy. Player’s move" << endl;
	cout << "is marked with X.Computer’s move is marked with O" << endl;
	cout << "Start? (y/n):" << endl;
}

void displayBoard(char board[]) {
	for (int i = 0; i < 5; i++) {
		if (i % 2 == 1) {
			cout << "----------      ----------      ----------" << endl;
		}
		else {
			for (int j = 0; j < 3; j++) {
				cout << '|';
				for (int k = 0; k < 3; k++) {
					cout << board[((i % 5)/2) * 3 + k + 9 * j] << " |";
				}
				cout << '\t';
			}
			cout << endl;
		}
	}
}


bool checkIfLegal(int cellNbre, char board[]) {
	if (cellNbre > 27 || cellNbre < 1 || board[cellNbre - 1] != ' ') {
		cout << "Invalid input, type an input again" << endl;
		return false;
	}
	board[cellNbre - 1] = 'x';
	return true;
}



// 1 10 19 (1-9)
bool check1(char board[], int coor) {
	if (board[coor] != ' '&&board[coor] == board[coor + 9] && board[coor] == board[coor + 18]) {
		return true;
	}
	return false;
}

// 1 2 3 ( 1 4 7   10 13 16  19 22 25)
bool check2(char board[], int coor) {
	if (board[coor] != ' ' && board[coor] == board[coor + 1] && board[coor] == board[coor + 2]) {
		return true;
	}
	return false;
}

//1 4 7(123       10 11 12    19 20 21)
bool check3(char board[], int coor) {
	if (board[coor] != ' ' && board[coor] == board[coor + 3] && board[coor] == board[coor + 6]) {
		return true;
	}
	return false;
}

// diagonal
//5 14 23
bool check4(char board[], int coor) {
	if (board[coor] != ' ' && board[coor] == board[coor - 4] && board[coor] == board[coor + 4]) {
		return true;
	}
	else if(board[coor] != ' ' && board[coor] == board[coor - 2] && board[coor] == board[coor + 2]){
		return true;
	}
	return false;
}
//13 14 15
bool check5(char board[], int coor) {
	if (board[coor] != ' ' && board[coor] == board[coor + 12] && board[coor] == board[coor - 12]) {
		return true;
	}
	else if (board[coor] != ' ' && board[coor] == board[coor - 6] && board[coor] == board[coor + 6]) {
		return true;
	}
	return false;
}

//11 14 17
bool check6(char board[], int coor) {
	if (board[coor] != ' ' && board[coor] == board[coor - 10] && board[coor] == board[coor + 10]) {
		return true;
	}
	else if (board[coor] != ' ' && board[coor] == board[coor - 8] && board[coor] == board[coor + 8]) {
		return true;
	}
	return false;
}

//14

bool check7(char board[], int coor) {
	if (board[coor] != ' ' && board[coor] == board[coor - 13] && board[coor] == board[coor + 13]) {
		return true;
	}
	else if (board[coor] != ' ' && board[coor] == board[coor - 11] && board[coor] == board[coor + 11]) {
		return true;
	}
	else if (board[coor] != ' ' && board[coor] == board[coor - 7] && board[coor] == board[coor + 7]) {
		return true;
	}
	else if (board[coor] != ' ' && board[coor] == board[coor - 5] && board[coor] == board[coor + 5]) {
		return true;
	}
	return false;
}

bool checkTie(char board[]) {
	for (int i = 0; i < 27; i++) {
		if (board[i] == ' ') {
			return false;
		}
		
	}
	return true;
}
bool checkWinner(char board[]) {
	//tie
	if (checkTie(board) == true) {
		return false;
	}
	
	//check1
	for (int i = 0; i < 9; i++) {
		if (check1(board, i)) {
			return true;
		}
	}
	//check2
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (check2(board, i * 9 + j * 3)) {
				return true;
			}
		}
	}
	//check3
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (check3(board, 9 * i + j)) {
				return true;
			}
		}
	}
	//check4
	for (int i = 0; i < 3; i++) {
		if (check4(board, 9 * i + 4)) {
			return true;
		}
	}

	//check5
	for (int i = 12; i < 15; i++) {
		if (check5(board, i)) {
			return true;
		}
	}

	//check6
	for (int i = 10; i < 17; i += 3) {
		if (check6(board, i)) {
			return true;
		}
	}
	if (check7(board, 13)) {
		return true;
	}

	return false;
}

void computerMove(char board[]) {
	for (int i = 0; i < 27; i++) {
		if (board[i] == ' ') {
			board[i] = 'o';
			if (checkWinner(board)) {
				return;
			}
			board[i] = ' ';
		}
	}
	for (int i = 0; i < 27; i++) {
		if (board[i] == ' ') {
			board[i] = 'x';
			if (checkWinner(board)) {
				board[i] = 'o';
				return;
			}
			board[i] = ' ';
		}
	}
	for (int i = 0; i < 27;i++) {
		if (board[i] == ' ') {
			board[i] = 'o';
			return;
		}
	}

}
