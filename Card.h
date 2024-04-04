#pragma once
#include<iostream>

enum class Suits {
    hearts,
    clubs,
    spades,
    diamonds
};

enum class CardNames {
    ace,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king
};

class Card {
public:
    
    Card(Suits s, CardNames c);
    int getValue() const;
    std::string getFileName() const;
    const bool isVisibleForAll() const;
private:
    Suits suit;
    CardNames cardName;
    int value;
    bool isVisibleForEveryone;
    bool isVisibleForPlayer;
};
