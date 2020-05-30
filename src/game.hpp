#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "player.hpp"

class Game
{
private:
    sf::RenderWindow window;
    sf::Event event;
    Player player;
    sf::Clock deltaClock;
    float deltaTime;

public:
    Game();
    bool running();
    void pollEvents();
    void update();
    void render();

};
#endif
