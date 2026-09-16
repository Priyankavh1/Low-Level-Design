#include "Board.h"
#include "InvalidMoveException.h"
#include <iostream>
#include <string>

using namespace std;

void Board::initializeBoard() {
    grid_.resize(size_);
    for (int i = 0; i < size_; i++) {
        grid_[i].resize(size_);
    }
}

void Board::validatePosition(int row, int col) const {
    if (row < 0 || row >= size_ || col < 0 || col >= size_) {
        throw InvalidMoveException(
            "Position (" + to_string(row) + ", " +
            to_string(col) + ") is out of bounds"
        );
    }
}

Board::Board(int size) : size_(size) {
    initializeBoard();
}

void Board::placeSymbol(int row, int col, Symbol symbol) {
    validatePosition(row, col);
    grid_[row][col].setSymbol(symbol);
}

bool Board::isCellEmpty(int row, int col) const {
    validatePosition(row, col);
    return grid_[row][col].isEmpty();
}

bool Board::isFull() const {
    for (int i = 0; i < size_; i++) {
        for (int j = 0; j < size_; j++) {
            if (grid_[i][j].isEmpty()) {
                return false;
            }
        }
    }
    return true;
}

const Cell& Board::getCell(int row, int col) const {
    validatePosition(row, col);
    return grid_[row][col];
}

int Board::getSize() const { return size_; }

void Board::printBoard() const {
    cout << endl;
    for (int i = 0; i < size_; i++) {
        for (int j = 0; j < size_; j++) {
            cout << " " << getDisplayChar(grid_[i][j].getSymbol()) << " ";
            if (j < size_ - 1) cout << "|";
        }
        cout << endl;
        if (i < size_ - 1) {
            cout << string(size_ * 4 - 1, '-') << endl;
        }
    }
    cout << endl;
}