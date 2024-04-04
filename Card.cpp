#include "Card.h"
#include "Display.h"
Card::Card(Suits s, CardNames c) : suit(s), cardName(c), isVisibleForEveryone(false), isVisibleForPlayer(false)
{       //according to the game rules, set the values of cards
        switch (c) {
        case CardNames::ace:
            value = 0;
            break;
        case CardNames::two:
            value = 2;
            break;
        case CardNames::three:
            value = 3;
            break;
        case CardNames::four:
            value = 4;
            break;
        case CardNames::five:
            value = 5;
            break;
        case CardNames::six:
            value = 6;
            break;
        case CardNames::seven:
            value = 7;
            break;
        case CardNames::eight:
            value = 8;
            break;
        case CardNames::nine:
            value = 9;
            break;
        case CardNames::ten:
            value = 10;
            break;
        case CardNames::jack:
            value = 10;
            break;
        case CardNames::queen:
            value = 10;
            break;
        case CardNames::king:
            // Kings value dependent on suits
            if (s == Suits::clubs || s == Suits::diamonds)
                value = 10; 
            else if (s == Suits::spades)
                value = 1;
            else if (s == Suits::hearts)
                value = 13;
            break;
        }
}

int Card::getValue() const
{
    return value;
}

std::string Card::getFileName() const
{
    std::string cardValue;
    switch (cardName) {
    case CardNames::ace:
        cardValue = "ace";
        break;
    case CardNames::two:
        cardValue = "2";
        break;
    case CardNames::three:
        cardValue = "3";
        break;
    case CardNames::four:
        cardValue = "4";
        break;
    case CardNames::five:
        cardValue = "5";
        break;
    case CardNames::six:
        cardValue = "6";
        break;
    case CardNames::seven:
        cardValue = "7";
        break;
    case CardNames::eight:
        cardValue = "8";
        break;
    case CardNames::nine:
        cardValue = "9";
        break;
    case CardNames::ten:
        cardValue = "10";
        break;
    case CardNames::jack:
        cardValue = "jack";
        break;
    case CardNames::queen:
        cardValue = "queen";
        break;
    case CardNames::king:
        cardValue = "king";
        break;
    }

    std::string cardSuit;
    switch (suit) {
    case Suits::hearts:
        cardSuit = "hearts";
        break;
    case Suits::clubs:
        cardSuit = "clubs";
        break;
    case Suits::spades:
        cardSuit = "spades";
        break;
    case Suits::diamonds:
        cardSuit = "diamonds";
        break;
    }

    return "img/" + cardValue + "_of_" + cardSuit + ".png";
}

const bool Card::isVisibleForAll() const
{
    return isVisibleForEveryone;
}




