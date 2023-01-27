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
  Joueur(string prenom,string nom,size_t x, size_t y,string image);
  ~Joueur(){};
  float getX(){return _x;}
  float getY(){return _y;}
  void Set_velocity(sf::Vector2f velocite){velocity = velocite;}
  sf::Vector2f Get_velocity(){return velocity;}
  virtual void update(){};
  Sprite getSprite() {return sprite;}
  virtual std::string allInfo() const;
  void borderlimits(const sf::RenderWindow &window);
  bool getJoueuractif1(){return joueuractif1;}  
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
