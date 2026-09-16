#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Symbol.h"

class Player {
private:
    const std::string name_;
    const Symbol symbol_;

public:
    Player(const std::string& name, Symbol symbol);

    const std::string& getName() const;
    Symbol getSymbol() const;
    std::string toString() const;
};

#endif