#pragma once
#include<iostream>
#include<cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include "attaquant.hh"
#include "joueur.hh"

using namespace std;

class Attaquant_Normal: public Attaquant{
 public:
  Attaquant_Normal(string prenom,string nom,float x, float y,string image);
  

 protected:
  
};

