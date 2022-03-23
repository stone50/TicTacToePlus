#pragma once

#include <vector>
#include "api.h"

class TPGame {
private:
	int boardWidth;											// board width
	int boardHeight;										// board height
	int connectX;											// number of symbols in a line required to win
	std::vector<std::vector<char>> board;					// game board
	bool gameOver;											// true if the game is over, otherwise false
	char winner;											// 'X' if X's won, 'O' if O's won, otherwise '-'
	char playerToMove;										// 'X' if it is X's turn, 'O' if it is O's turn, otherwise '-'
	int plyCount;											// increments every time a symbol is added to the board
	std::vector<std::vector<std::vector<char>>> history;	// stores the board state of every move made

	void checkGameOver(int moveCol, int moveRow);

public:
	TTTP_API TPGame();

	TTTP_API TPGame(const TPGame& other);

	TTTP_API TPGame(int _boardWidth, int _boardHeight, int _connectX);

	TTTP_API ~TPGame();

	TTTP_API TPGame& operator=(const TPGame& other);

	TTTP_API bool makeMove(int col, int row);

	TTTP_API int getBoardWidth();

	TTTP_API int getBoardHeight();

	TTTP_API int getConnectX();

	TTTP_API char getCellAt(int col, int row);

	TTTP_API char getCellInHistory(int ply, int col, int row);

	TTTP_API bool getGameOver();

	TTTP_API char getWinner();

	TTTP_API char getPlayerToMove();

	TTTP_API int getPlyCount();
};