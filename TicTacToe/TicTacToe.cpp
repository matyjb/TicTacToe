#pragma once
#include "stdafx.h"

Board board;
char input;
char whichPlayer; //X or O
bool gameInProgress;

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
	board.SetFields("X X X X X");
	input = ' ';
	whichPlayer = 'O';
	gameInProgress = true;
}

void Update() {
	switch (input)
	{
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
		board.PutCharacterOnSelectedField(whichPlayer);
		AlterPlayer();
		break;
	case 'q':
		gameInProgress = false;
		break;
	default:
		break;
	}
}

int main() {
	Setup();
	//main loop
	while (gameInProgress) {
		system("cls");
		std::cout << "Tura: " << whichPlayer << std::endl << std::endl;
		board.Draw();
		input = _getch();
		Update();
	}



	system("pause");
	return 0;
}