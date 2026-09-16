#include "Game.h"
#include "InvalidMoveException.h"

using namespace std;

bool Game::checkWin(int row, int col, Symbol symbol) const {
    int n = board_->getSize();

    bool rowWin = true;
    for (int c = 0; c < n; c++) {
        if (board_->getCell(row, c).getSymbol() != symbol) { rowWin = false; break; }
    }
    if (rowWin) return true;

    bool colWin = true;
    for (int r = 0; r < n; r++) {
        if (board_->getCell(r, col).getSymbol() != symbol) { colWin = false; break; }
    }
    if (colWin) return true;

    if (row == col) {
        bool diagWin = true;
        for (int d = 0; d < n; d++) {
            if (board_->getCell(d, d).getSymbol() != symbol) { diagWin = false; break; }
        }
        if (diagWin) return true;
    }

    if (row + col == n - 1) {
        bool antiDiagWin = true;
        for (int d = 0; d < n; d++) {
            if (board_->getCell(d, n - 1 - d).getSymbol() != symbol) { antiDiagWin = false; break; }
        }
        if (antiDiagWin) return true;
    }

    return false;
}

Game::Game(shared_ptr<Player> player1, shared_ptr<Player> player2, int boardSize)
    : board_(make_unique<Board>(boardSize))
    , players_({player1, player2})
    , currentPlayerIndex_(0)
    , status_(GameStatus::IN_PROGRESS) {
}

void Game::makeMove(int row, int col) {
    lock_guard<mutex> lock(mtx_);

    if (status_ != GameStatus::IN_PROGRESS) {
        throw InvalidMoveException("Game is already over.");
    }

    if (!board_->isCellEmpty(row, col)) {
        throw InvalidMoveException("Cell is already occupied.");
    }

    Symbol currentSymbol = players_[currentPlayerIndex_]->getSymbol();
    board_->placeSymbol(row, col, currentSymbol);

    if (checkWin(row, col, currentSymbol)) {
        status_ = (currentSymbol == Symbol::X) ? GameStatus::WINNER_X : GameStatus::WINNER_O;
        return;
    }

    if (board_->isFull()) {
        status_ = GameStatus::DRAW;
        return;
    }

    currentPlayerIndex_ = 1 - currentPlayerIndex_;
}

const Board& Game::getBoard() const { return *board_; }

shared_ptr<Player> Game::getCurrentPlayer() const {
    return players_[currentPlayerIndex_];
}

GameStatus Game::getStatus() const { return status_; }

shared_ptr<Player> Game::getWinner() const {
    if (status_ == GameStatus::WINNER_X || status_ == GameStatus::WINNER_O) {
        Symbol winningSymbol = (status_ == GameStatus::WINNER_X) ? Symbol::X : Symbol::O;
        for (const auto& player : players_) {
            if (player->getSymbol() == winningSymbol) {
                return player;
            }
        }
    }
    return nullptr;
}

void Game::printBoard() const {
    board_->printBoard();
}