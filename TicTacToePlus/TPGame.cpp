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

char** TPGame::getBoard() {
	vector<char*> out;
	out.reserve(board.size());
	for (vector<char> col : board) {
		out.push_back(col.data());
	}

	return out.data();
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