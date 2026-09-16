#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Symbol.h"
#include "GameStatus.h"

using namespace std;

int main() {
    auto alice = make_shared<Player>("Alice", Symbol::X);
    auto bob = make_shared<Player>("Bob", Symbol::O);

    Game game(alice, bob, 3);

    cout << "========== TIC TAC TOE ==========\n";

    game.makeMove(0, 0);
    game.makeMove(1, 0);
    game.makeMove(0, 1);
    game.makeMove(1, 1);
    game.makeMove(0, 2);

    game.printBoard();

    cout << "Result: ";
    switch (game.getStatus()) {
        case GameStatus::WINNER_X: cout << "WINNER_X\n"; break;
        case GameStatus::WINNER_O: cout << "WINNER_O\n"; break;
        case GameStatus::DRAW: cout << "DRAW\n"; break;
        default: cout << "IN_PROGRESS\n";
    }

    auto winner = game.getWinner();
    if (winner != nullptr) {
        cout << "Winner: " << winner->getName() << "\n";
    }

    return 0;
}