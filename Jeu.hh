#pragma once
#include<iostream>
#include<cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include "joueur.hh"
#include "ballon.hh"
#include "attaquant_hero.hh"
#include "goal_hero.hh"
#include "attaquant_normal.hh"
#include "goal_normal.hh"
#include "goal.hh"
#include "attaquant.hh"
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;

class Jeu{
 public:
 Jeu();
 ~Jeu(){};
 string Get_Pays1(){return pays2;}
 string Get_Pays2(){return pays3;}
 string Get_Map(){return map; }
 void Choix_Joueur1();
 void Choix_Joueur2();
 void Choix_Map();
 void start(Ballon &ball, sf::RenderWindow &window,int gameStartDelay,int gameStartCounter);
 bool check_goal(Ballon &ball,Joueur &joueurr1,Joueur &joueur2,Joueur &joueur3,Joueur &joueur4,sf::RenderWindow &window,int &gameStartCounter);
 int Choix_Mode();
 bool afficher_regles();

 private:
 

std::string pays2;
std::string pays3;
std::string map;
vector<string> c1;
vector<string> c2;
static int compt_J1;
static int compt_J2;
 
};

std::ostream& operator<<(std::ostream& os, const Jeu &e);