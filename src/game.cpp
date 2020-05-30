#include "game.hpp"
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>

Game::Game()
{
    window.create(sf::VideoMode(1024, 768), "rotations");
    window.setFramerateLimit(60);
}

bool Game::running()
{
    return window.isOpen();
}

void Game::pollEvents()
{
    deltaTime = deltaClock.restart().asSeconds();
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window.close();
        }
    }

}

void Game::update()
{
    player.playerMovement(deltaTime);

}

void Game::render()
{
    window.clear();

    player.drawPlayer(window);

    window.display();
}
