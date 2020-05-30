#include "player.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

Player::Player()
{
    playerTexture.loadFromFile("./content/car.png");
    player.setTexture(playerTexture);
    player.setPosition(sf::Vector2f(400.f, 400.f));
    playerOrigin = sf::Vector2f(player.getTexture()->getSize().x/2, player.getTexture()->getSize().y/2);
    player.setOrigin(playerOrigin);
    isMoving = false;
    float speed = 0;
}

void Player::playerMovement(float& deltaTime)
{
    if (speed > 0){
        isMoving = true;
    }else{
        isMoving = false;
    }
    // If i press W
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        player.move(cos(player.getRotation() * 3.14 /180) * speed * deltaTime, -sin(player.getRotation() * 3.14 / 180)* -speed * deltaTime); 
        isMoving = true;
        if (speed <= 200.f){
            speed += 2.f;
            flag = 'w';
        }
    }
    // If i press S
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        player.move(cos(player.getRotation() * 3.14 /180) * -speed * deltaTime, -sin(player.getRotation() * 3.14 / 180)* speed * deltaTime);
        isMoving = true;
        if (speed <= 100.f){
            speed += 2.f;
            flag = 's';
        }
    }
    // Rotations
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && isMoving){
        player.rotate(-2.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && isMoving){
        player.rotate(2.f);
    }
    // Deceleration
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == false && sf::Keyboard::isKeyPressed(sf::Keyboard::S) == false){
        if (speed >= 0){
            if (flag == 'w'){
                player.move(cos(player.getRotation() * 3.14 /180) * speed * deltaTime, -sin(player.getRotation() * 3.14 / 180)* -speed * deltaTime); 
                speed -= 2.f;
            }
            if (flag == 's'){
                player.move(cos(player.getRotation() * 3.14 /180) * -speed * deltaTime, -sin(player.getRotation() * 3.14 / 180)* speed * deltaTime);
                speed -= 2.f;
            } 
        }
     
    }
}
void Player::drawPlayer(sf::RenderWindow& window)
{
    window.draw(player);
}
