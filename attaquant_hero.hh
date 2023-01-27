#pragma once
#include<iostream>
#include<cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include "math.h"
#include "ballon.hh"
#include "attaquant.hh"
#include "joueur.hh"
#include <SFML/Graphics.hpp>
using namespace std;

class Attaquant_Hero: public Attaquant{
 public:
  Attaquant_Hero(string prenom,string nom,float x, float y,string image);

  std::string allInfo() const;
  void update(Ballon &ball);
  void distance(Ballon &ball);
 private:
 
  std::string _capacite;
  size_t _spe;
};


