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
    Ballon(size_t x, size_t y);
    ~Ballon(){};
    float getX() const {return _x;}
    float getY() const {return _y;}
    float getAcc()const {return ball_acceleration;}
    float getMaxSpeed() const {return ball_maxSpeed;}
    void setballLaunched(bool signal){ballLaunched = signal;}
    void setBallVelocity(sf::Vector2f velocite){ball_velocity = velocite;}
    Vector2f getballVelocity(){return ball_velocity;}
    bool getballLaunched(){return ballLaunched;}
    Sprite getsprite(){return ball_sprite;}
    void balllimit(const sf::RenderWindow &window);
    void update();
    void manage_collision(Joueur &player);
    void init_ball();

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
