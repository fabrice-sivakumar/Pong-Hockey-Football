#pragma once
#include<iostream>
#include<cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "joueur.hh"

using namespace std;
using namespace sf;

class Ballon{
    public:
    Ballon(size_t x, size_t y):_x(x),_y(y){
       if (!ball_texture.loadFromFile("ball.png")) {
            std::cout << "Erreur lors du chargement de l'image france.png" << std::endl;
        }

        //Initialiser la vitesse et accélération du ballon
        ball_sprite.setTexture(ball_texture);
        ball_sprite.setPosition(_x, _y);
        ball_acceleration = 0.5f;
        ball_maxSpeed = 2.0f;
        
        ballLaunched = false;
    };
    ~Ballon(){};
    float getX() const {return _x;}
    float getY() const {return _y;}
    //void setX(size_t x) {_x=x;}
    //void setY(size_t y) {_y=y;}
     float getAcc()const {return ball_acceleration;}
    float getMaxSpeed() const {return ball_maxSpeed;}
    void setballLaunched(bool signal){
        ballLaunched = signal;
    }
    void setBallVelocity(sf::Vector2f velocite){
        ball_velocity = velocite;
    }
    Vector2f getballVelocity(){
        return ball_velocity;
    }
    bool getballLaunched(){
        return ballLaunched;
    }

    Sprite getsprite(){
        return ball_sprite;
    }

    void balllimit(const sf::RenderWindow &window){
        // Vérifier si le ballon sort de l'écran
        sf::Vector2f ballPos = ball_sprite.getPosition();
        _x=ballPos.x;
        _y=ballPos.y;
        float ballWidth = ball_sprite.getGlobalBounds().width;
        float ballHeight = ball_sprite.getGlobalBounds().height;
        if (ballPos.x < 0 && (ballPos.y <170 || ballPos.y > 290)) {
            ball_velocity.x = -ball_velocity.x;
            ball_sprite.setPosition(0, ballPos.y);
        }
        if (ballPos.x > window.getSize().x - ballWidth && (ballPos.y <170 || ballPos.y > 290)) {
            ball_velocity.x = -ball_velocity.x;
            ball_sprite.setPosition(window.getSize().x - ballWidth, ballPos.y);
        }
        if (ballPos.y < -1) {
            ball_velocity.y = -ball_velocity.y;
            ball_sprite.setPosition(ballPos.x, 0);
        }
        if (ballPos.y > window.getSize().y - ballHeight+1) {
            ball_velocity.y = -ball_velocity.y;
            ball_sprite.setPosition(ballPos.x, window.getSize().y - ballHeight);
        }
    }

       void update() {
        // Limiter la vitesse maximale
        if (ball_velocity.x > ball_maxSpeed)
            ball_velocity.x = ball_maxSpeed;
        if (ball_velocity.x < -ball_maxSpeed)
            ball_velocity.x = -ball_maxSpeed;
        if (ball_velocity.y > ball_maxSpeed)    
            ball_velocity.y = ball_maxSpeed;
        if (ball_velocity.y < -ball_maxSpeed)
            ball_velocity.y = -ball_maxSpeed;

        // Appliquer la vitesse à la position
        ball_sprite.move(ball_velocity);
        }
        void manage_collision(Joueur &player) {
        if(player.getSprite().getGlobalBounds().intersects(ball_sprite.getGlobalBounds())) {
        ball_velocity.x = player.Get_velocity().x;
        ball_velocity.y = player.Get_velocity().y;
        if (ball_velocity.x > 0)
            ball_velocity.x += ball_acceleration;
        else
            ball_velocity.x -= ball_acceleration;
        if (ball_velocity.y > 0)
            ball_velocity.y +=ball_acceleration;
        else
            ball_velocity.y -= ball_acceleration;
            
        }
        }

        void init_ball(){
            ball_sprite.setPosition(360,230);
            ball_velocity.x = 0;
            ball_velocity.y = 0;
            ballLaunched = false;
        }


private:
    sf::Texture ball_texture;
    sf::Sprite ball_sprite;
    sf::Vector2f ball_velocity;
    bool ballLaunched;
    float ball_acceleration;
    float ball_maxSpeed;

protected:

    float _x;
    float _y;

    
};