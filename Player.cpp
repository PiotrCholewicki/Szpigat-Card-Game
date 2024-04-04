#include "Player.h"

Player::Player() : points(0)
{

}

Player::Player(std::string name_) : points(0), name(name_)
{
}

void Player::drawCard(Deck &d)
{
	this->playersHand.push_back(d.dealTopCard());
	
}

int Player::getPoints()
{
	return points;
}

std::vector<Card> Player::getCards() const
{
	return playersHand;
}


