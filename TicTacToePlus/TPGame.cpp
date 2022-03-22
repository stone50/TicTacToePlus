#include "TPGame.h"

using namespace std;

TPGame::TPGame() :
	boardWidth(3),
	boardHeight(3),
	connectX(3),
	board(vector<vector<char>>(3, vector<char>(3, '-'))),
	gameOver(false),
	winner('-'),
	playerToMove('X'),
	plyCount(0)
{}

TPGame::TPGame(const TPGame& other) :
	boardWidth(other.boardWidth),
	boardHeight(other.boardHeight),
	connectX(other.connectX),
	board(other.board),
	gameOver(other.gameOver),
	winner(other.winner),
	playerToMove(other.playerToMove),
	plyCount(other.plyCount)
{}

TPGame::TPGame(int _boardWidth, int _boardHeight, int _connectX) :
	boardWidth(_boardWidth),
	boardHeight(_boardHeight),
	connectX(_connectX),
	board(vector<vector<char>>(_boardWidth, vector<char>(_boardHeight, '-'))),
	gameOver(false),
	winner('-'),
	playerToMove('X'),
	plyCount(0)
{}

TPGame::~TPGame() {
	board.~vector();
}

TPGame& TPGame::operator=(const TPGame& other) {
	boardWidth = other.boardWidth;
	boardHeight = other.boardHeight;
	connectX = other.connectX;
	board = other.board;
	gameOver = other.gameOver;
	winner = other.winner;
	playerToMove = other.playerToMove;
	plyCount = other.plyCount;
	return *this;
}

void TPGame::checkGameOver(int moveCol, int moveRow) {
	char player = board[moveCol][moveRow];
	int left = max(moveCol - connectX + 1, 0);
	int right = min(moveCol, boardWidth - connectX);
	int top = max(moveRow - connectX + 1, 0);
	int bottom = min(moveRow, boardHeight - connectX);

	// left to right
	for (int leftCellCol = left; leftCellCol <= right; leftCellCol++) {
		for (int colOffset = 0; colOffset < connectX; colOffset++) {
			if (board[leftCellCol + colOffset][moveRow] != player) {
				break;
			}
			else if (colOffset == connectX - 1) {
				// game won
				gameOver = true;
				winner = player;
				playerToMove = '-';
				return;
			}
		}
	}

	// top to bottom
	for (int topCellRow = top; topCellRow <= bottom; topCellRow++) {
		for (int rowOffset = 0; rowOffset < connectX; rowOffset++) {
			if (board[moveCol][topCellRow + rowOffset] != player) {
				break;
			}
			else if (rowOffset == connectX - 1) {
				// game won
				gameOver = true;
				winner = player;
				playerToMove = '-';
				return;
			}
		}
	}

	int topLeftOffset = min(moveCol - left, moveRow - top);
	int bottomRightOffset = min(right - moveCol, bottom - moveRow);
	int bottomLeftOffset = min(moveCol - left, min(moveRow + connectX - 1, boardHeight - 1) - moveRow);
	int topRightOffset = min(right - moveCol, moveRow - max(connectX - 1, moveRow));

	// top left to bottom right
	for (int offset = -topLeftOffset; offset <= bottomRightOffset; offset++) {
		for (int offsetOffset = 0; offsetOffset < connectX; offsetOffset++) {
			if (board[moveCol + offset + offsetOffset][moveRow + offset + offsetOffset] != player) {
				break;
			}
			else if (offsetOffset == connectX - 1) {
				// game won
				gameOver = true;
				winner = player;
				playerToMove = '-';
				return;
			}
		}
	}

	// bottom left to top right
	for (int offset = -bottomLeftOffset; offset <= topRightOffset; offset++) {
		for (int offsetOffset = 0; offsetOffset < connectX; offsetOffset++) {
			if (board[moveCol + offset + offsetOffset][moveRow - offset - offsetOffset] != player) {
				break;
			}
			else if (offsetOffset == connectX - 1) {
				// game won
				gameOver = true;
				winner = player;
				playerToMove = '-';
				return;
			}
		}
	}

	// check for draw
	if (plyCount == boardWidth * boardHeight) {
		gameOver = true;
		winner = '-';
		playerToMove = '-';
		return;
	}
}

bool TPGame::makeMove(int col, int row) {
	char& cell = board[col][row];
	if (gameOver || cell != '-') {
		return false;
	}

	cell = playerToMove;
	plyCount++;
	checkGameOver(col, row);
	if (!gameOver) {
		playerToMove = playerToMove == 'X' ? 'O' : 'X';
	}
	return true;
}

int TPGame::getBoardWidth() {
	return boardWidth;
}

int TPGame::getBoardHeight() {
	return boardHeight;
}

int TPGame::getConnectX() {
	return connectX;
}

char TPGame::getCellAt(int col, int row) {
	return board[col][row];
}

bool TPGame::getGameOver() {
	return gameOver;
}

char TPGame::getWinner() {
	return winner;
}

char TPGame::getPlayerToMove() {
	return playerToMove;
}

int TPGame::getPlyCount() {
	return plyCount;
}