#pragma once
#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include "Display.h"
class Deck {
public:
	Deck();
	~Deck();
	void shuffle();
	void printSize();
	Card dealTopCard();
	void clear();
	bool isEmpty() const;
	//friend std::ostream& operator<<(std::ostream& s, const Deck& deck);
private:
	std::vector<Card> cards;

};

