#include "Game.h"

void Game::initVariables()
{
    //draw 4 cards for players in the beggining of the round
    for (int i = 0; i < 4; i++) {
        this->player1.drawCard(this->drawableCards);
    }
    
}

void Game::initWindow()
{
	this->videoMode.width = 1080;
	this->videoMode.height = 720;
	//this->videoMode.getDesktopMode; //for test
	this->window = new sf::RenderWindow(this->videoMode, "Szpigat", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initDecks()
{
    this->drawableCards.shuffle();
    this->stackOfCards.clear();
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initDecks();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
        case sf::Event::Closed: { //closing on clicking the top right corner "X"
            this->window->close();
            break;
        }
        case sf::Event::KeyPressed: { //close on clicking escape
            if (this->ev.key.code == sf::Keyboard::Escape) {
                this->window->close();
            }
            break;
        }

        }
    }
}

void Game::updateMousePositions()
{
    // updates the mouse positions: mouse position to window (Vector2i)
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow); //same but in floats
}

void Game::update()
{

    this->pollEvents();
    this->updateMousePositions();
}

void Game::renderPlayerCards()
{
    sf::Texture texture;
    
    float pos = 300;
    for (const auto& card : this->player1.getCards()) {
        if (!card.isVisibleForAll()) {
            if (texture.loadFromFile(card.getFileName())) {
                sf::Sprite sprite(texture);
                sprite.setPosition(pos, 550);
                sprite.setScale(0.2f, 0.2f);
                this->window->draw(sprite);
                pos += 100;
            }
        }
        else {
            if (texture.loadFromFile("img/back.png")) {
                sf::Sprite sprite(texture);
                sprite.setPosition(pos, 550);
                sprite.setScale(0.2f, 0.2f);
                
                this->window->draw(sprite);
                pos += 100;
            }
        }

    }
}

void Game::render()
{
    /*
    - clear old frame
    - render objects
    - display frame in window

    */
    this->window->clear(sf::Color(0, 128, 43));
    //Draw game objects
    this->renderPlayerCards();
    this->window->display();
}