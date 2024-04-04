#pragma once
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "Player.h"
#include "Display.h"
#include "Deck.h"
#include "Card.h"
class Game {
private:
	
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	//Game variables
	Deck drawableCards;
	Deck stackOfCards;
	Player player1;


	void initVariables();
	void initWindow();
	void initDecks();

public:
	Game();
	virtual ~Game();
	//Accesors
	const bool isRunning() const;
	//Functions
	void pollEvents();
	void updateMousePositions();

	void update();
	void renderPlayerCards();
	void render();
};