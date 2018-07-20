#include "stdafx.h"
#include "board.h"


Board::Board() {
	fields = "         ";
	selectedField = 4;
}

Board::~Board()
{
}

void Board::ClearBoard() {
	fields = "         ";
}

char Board::CheckWin() {
	if (fields[1] == fields[2] && fields[2] == fields[3] && fields[1] != ' ') return fields[1];
	if (fields[4] == fields[5] && fields[5] == fields[6] && fields[4] != ' ') return fields[4];
	if (fields[7] == fields[8] && fields[8] == fields[9] && fields[7] != ' ') return fields[7];

	if (fields[1] == fields[4] && fields[4] == fields[7] && fields[1] != ' ') return fields[1];
	if (fields[2] == fields[5] && fields[5] == fields[8] && fields[2] != ' ') return fields[2];
	if (fields[3] == fields[6] && fields[6] == fields[9] && fields[3] != ' ') return fields[3];

	if (fields[1] == fields[5] && fields[5] == fields[9] && fields[1] != ' ') return fields[1];
	if (fields[3] == fields[5] && fields[5] == fields[7] && fields[3] != ' ') return fields[3];
	return ' ';
}

void Board::Draw() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (selectedField == i * 3 + j) {
				std::cout << '[' << fields[i * 3 + j] << ']';
			}
			else {
				std::cout << ' ' << fields[i * 3 + j] << ' ';
			}
			if (j != 2) {
				std::cout << char(186);
			}
		}
		std::cout << std::endl;
		if (i != 2) {
			std::cout << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << std::endl;
		}
	}
}
void Board::MoveCursorUp() {
	if (selectedField != 0 || selectedField != 1 || selectedField != 2) {
		selectedField -= 3;
	}
}
void Board::MoveCursorDown() {
	if (selectedField != 6 || selectedField != 7 || selectedField != 8) {
		selectedField += 3;
	}
}
void Board::MoveCursorLeft() {
	if (selectedField != 0 || selectedField != 3 || selectedField != 6) {
		selectedField--;
	}
}
void Board::MoveCursorRight() {
	if (selectedField != 2 || selectedField != 5 || selectedField != 8) {
		selectedField++;
	}
}
std::string Board::GetFields() {
	return fields;
}
bool Board::SetFields(std::string newFields) {
	if (newFields.length() == 9) {
		fields = newFields;
		return true;
	}
	return false;
}