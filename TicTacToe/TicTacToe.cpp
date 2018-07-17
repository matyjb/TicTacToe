#pragma once
#include "stdafx.h"

int main() {
	Board board;
	board.SetFields("X X X X X X");
	board.Draw();
	system("pause");
	return 0;
}