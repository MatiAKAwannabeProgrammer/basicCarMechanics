#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Player
{
private:
    sf::Sprite player;
    sf::Texture playerTexture;
    sf::Vector2f playerOrigin;
    bool isMoving;
    float speed;
    char flag;

public:
    Player();
    void playerMovement(float& deltaTime);
    void drawPlayer(sf::RenderWindow& window);

};
#endif
