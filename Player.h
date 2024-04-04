#pragma once
#include "Deck.h"

class Player
{
public:
	Player();
	Player(std::string name_);
	void drawCard(Deck &d);
	int getPoints();
	std::vector<Card> getCards() const;
private:
	std::string name;
	int points;
	std::vector<Card> playersHand;

};

