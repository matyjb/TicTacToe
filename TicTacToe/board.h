#pragma once
class Board {
	int selectedField;
public:
	std::string fields;
	Board();
	~Board();
	void ClearBoard();
	char CheckWin();
	void Draw();
	void MoveCursorUp();
	void MoveCursorDown();
	void MoveCursorLeft();
	void MoveCursorRight();
	bool PutCharacterOnSelectedField(char);
	std::string GetFields();
	bool SetFields(std::string);
};

