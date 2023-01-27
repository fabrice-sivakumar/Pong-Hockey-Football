#pragma once
#include<iostream>
#include<cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


using namespace std;

class Joueur{
public:
  Joueur(string prenom,string nom,size_t x, size_t y,string image):_prenom(prenom),_nom(nom),_x(x),_y(y),_image(image){
    // Charger l'image du joueur
        if (!texture.loadFromFile(_image)) {
            std::cout << "Erreur lors du chargement de l'image france.png" << std::endl;
        }

        // Initialiser le sprite du joueur
        sprite.setTexture(texture);
        sprite.setPosition(_x, _y);

        // Initialiser la vitesse et l'accélération du joueur
        velocity = sf::Vector2f(0, 0);
        acceleration = 0.1;
        maxSpeed = 1.0;
        _numero=_nbJoueur;
        _nbJoueur++;
  };
  ~Joueur(){
    };

  float getX(){return _x;}
   float getY(){return _y;}
   void Set_velocity(sf::Vector2f velocite){
        velocity = velocite;
    }
    sf::Vector2f Get_velocity(){
        return velocity;
    }
  virtual void update() {

    }
    Sprite getSprite() {
        return sprite;
    }
  virtual std::string allInfo() const;
   void borderlimits(const sf::RenderWindow &window){        
        sf::Vector2f playerPos = sprite.getPosition();
        _x=playerPos.x;
        _y=playerPos.y;
        
        if (_numero%2==1)
        {
            if (playerPos.x < 0)
                sprite.setPosition(0, playerPos.y);
            if (playerPos.x > (window.getSize().x - sprite.getGlobalBounds().width)/2)
                sprite.setPosition((window.getSize().x - sprite.getGlobalBounds().width)/2, playerPos.y);
        }
        else 
        {
            if (playerPos.x < (window.getSize().x - sprite.getGlobalBounds().width)/2)
                sprite.setPosition((window.getSize().x - sprite.getGlobalBounds().width)/2, playerPos.y);
            if (playerPos.x > window.getSize().x - sprite.getGlobalBounds().width)
                sprite.setPosition(window.getSize().x - sprite.getGlobalBounds().width, playerPos.y);
        }
        if (playerPos.y < -1)
            sprite.setPosition(playerPos.x, 0);
        if (playerPos.y > window.getSize().y - sprite.getGlobalBounds().height+1)
            sprite.setPosition(playerPos.x, window.getSize().y - sprite.getGlobalBounds().height);}
    bool getJoueuractif1(){
        return joueuractif1;
            }  
      void setPosition(float x,float y){sprite.setPosition(x, y);_x=x;_y=y;}
      int getNbJoueur(){return _nbJoueur;}
private:

protected:
    string _prenom;
    string _nom;
    float _x;
    float _y;
    string _poste;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    float acceleration;
    float maxSpeed;
    string _image;
    static bool joueuractif1; // pour savoir si le joueur actif de la paire de joueur 1 est attaquant ou gardien 
    static bool joueuractif2;   // pour savoir si le joueur actif de la paire de joueur 2 est attaquant ou gardien
    static int _nbJoueur; //compteur de joueur
    int _numero;
};

std::ostream& operator<<(std::ostream& os, const Joueur &e);