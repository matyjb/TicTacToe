#pragma once
#include "stdafx.h"

Board board;
GameState gameState;
char input;
char whichPlayer; //X or O
bool gameInProgress;
int scoreX;
int scoreO;


void AlterPlayer() {
	switch (whichPlayer)
	{
	case 'O':
		whichPlayer = 'X';
		break;
	case 'X':
		whichPlayer = 'O';
		break;
	default:
		break;
	}
}

void Setup() {
	board.ClearBoard();
	input = ' ';
	whichPlayer = 'O';
	gameState = StartScreen;
	scoreO = scoreX = 0;
}

void Update() {
	if (gameState == StartScreen) {
		switch (input) {
		case ' ':
			gameState = Playing;
			break;
		default:
			break;
		}
	}
	else if (gameState == Playing) {
		switch (input) {
		case 'w':
			board.MoveCursorUp();
			break;
		case 'a':
			board.MoveCursorLeft();
			break;
		case 's':
			board.MoveCursorDown();
			break;
		case 'd':
			board.MoveCursorRight();
			break;
		case 'f':
			if(board.PutCharacterOnSelectedField(whichPlayer))
				AlterPlayer();
			break;
		case 'q':
			gameState = GameOverFinal;
			break;
		default:
			break;
		}
	}
	else if (gameState == GameOver) {
		switch (input) {
		case 'q':
			gameState = GameOverFinal;
			break;
		case 'n':
			//new game setup;
			board.ClearBoard();
			whichPlayer = 'O';
			gameState = Playing;
			break;
		default:
			break;
		}

		
	}
	else if (gameState == GameOverFinal) {
		switch (input) {
		case 'q':
			gameState = Exit;
			break;
		case 'r':
			gameState = Playing;
			board.ClearBoard();
			whichPlayer = 'O';
			scoreO = scoreX = 0;
			break;
		default:
			break;
		}
	}
}

int main() {
	Setup();
	//main loop
	while (gameState != Exit) {
		system("cls");

		char checkWinResult = board.CheckWin();
		if (gameState == StartScreen) {
			std::cout << "Hello in TicTacToe by matyjb" << std::endl;
			std::cout << "Press Spacebar to continue" << std::endl;
			input = _getch();
		}
		else if (gameState == Playing) {
			std::cout << "Score:  <O: " << scoreO << "|" << scoreX << ":X>" << std::endl;
			std::cout << "Player: " << whichPlayer << std::endl << std::endl;
			board.Draw();
			if (checkWinResult == 'X') { 
				scoreX++; 
				gameState = GameOver; 
			}
			if (checkWinResult == 'O') { 
				scoreO++; 
				gameState = GameOver; 
			}
			if (checkWinResult == 'T') 
				gameState = GameOver;
			else input = _getch();
		}
		else if (gameState == GameOver) {
			
			std::cout << "Score:  <O: " << scoreO << "|" << scoreX << ":X>" << std::endl;
			std::cout << std::endl << std::endl;
			board.Draw();
			std::cout << std::endl;
			if (checkWinResult == 'X') std::cout << "X has won!";
			else if (checkWinResult == 'O') std::cout << "O has won!";
			else if (checkWinResult == 'T') std::cout << "it is a tie!";
			std::cout << std::endl;
			std::cout << "Press q to end match or n to start new game" << std::endl;
			input = _getch();
		}
		else if (gameState == GameOverFinal) {
			std::cout << "The match ended with final score:" << std::endl;
			std::cout << "<O: " << scoreO << "|" << scoreX << ":X>" << std::endl;
			if (scoreO > scoreX) std::cout << "O has won!" << std::endl;
			else if (scoreO < scoreX) std::cout << "X has won!" << std::endl;
			else std::cout << "It is a tie!" << std::endl;
			std::cout << std::endl;
			std::cout << "Press q to exit or r to restart" << std::endl;
			input = _getch();
		}

		Update();
	}
#ifdef NDEBUG
	system("pause");
#endif // NDEBUG

	return 0;
}