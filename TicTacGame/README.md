# Tic Tac Toe (C++)

A simple console-based Tic Tac Toe game implemented in C++, designed around a clean separation of concerns: board state, players, game rules, and game orchestration each live in their own class.

## Features

- Configurable board size (not limited to 3x3)
- Win detection across rows, columns, and both diagonals
- Draw detection when the board fills with no winner
- Thread-safe move handling via a mutex
- Clear error handling for invalid moves (out-of-bounds positions, occupied cells, moves after game over)

## Project Structure

```
TicTacGame/
├── HeaderFiles/
│   ├── Board.h
│   ├── Cell.h
│   ├── Game.h
│   ├── GameStatus.h
│   ├── InvalidMoveException.h
│   ├── Player.h
│   └── Symbol.h
├── entities/
│   ├── Board.cpp
│   ├── Cell.cpp
│   └── Player.cpp
├── enums/
│   └── Symbol.cpp
├── Game.cpp
└── TicTacToeDemo.cpp
```

## Class Overview

| Class | Responsibility |
|---|---|
| `Symbol` | Enum representing `X`, `O`, or `EMPTY` |
| `GameStatus` | Enum representing `IN_PROGRESS`, `WINNER_X`, `WINNER_O`, `DRAW` |
| `Cell` | A single board cell holding a `Symbol` |
| `Board` | The grid of cells; handles placement, bounds checking, fullness checks |
| `Player` | A player's name and assigned symbol |
| `Game` | Orchestrates turns, win/draw detection, and overall game state |
| `InvalidMoveException` | Thrown for out-of-bounds moves, occupied cells, or moves after the game has ended |

## Building

From the `TicTacGame` directory:

```bash
g++ -std=c++17 -pthread -IHeaderFiles \
    enums/Symbol.cpp entities/Cell.cpp entities/Player.cpp entities/Board.cpp \
    Game.cpp TicTacToeDemo.cpp -o tictactoe
```

## Running

```bash
./tictactoe
```

### Expected Output

```
========== TIC TAC TOE ==========

 X | X | X 
-----------
 O | O | _ 
-----------
 _ | _ | _ 

Result: WINNER_X
Winner: Alice
```

## Notes

- `Board`'s size is configurable via the `Game` constructor (`Game(player1, player2, boardSize)`), so the win-checking logic works for any NxN board, not just 3x3.
- `checkWin` only re-checks the row, column, and (when applicable) diagonals that pass through the most recently played cell, rather than rescanning the whole board on every move.
- `Game::makeMove` is guarded by a `std::mutex`, so it's safe to call from multiple threads, though the demo itself is single-threaded.
