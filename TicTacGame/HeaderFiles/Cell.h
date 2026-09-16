#ifndef CELL_H
#define CELL_H

#include "Symbol.h"

class Cell {
private:
    Symbol symbol_;

public:
    Cell();
    Symbol getSymbol() const;
    void setSymbol(Symbol symbol);
    bool isEmpty() const;
};

#endif