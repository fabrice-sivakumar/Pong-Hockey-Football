#pragma once
#include "joueur.hh"
#include <string>

using namespace std;

class Goalkeeper: public Joueur{
 public:
 Goalkeeper(string prenom,string nom,float x, float y,string image);
 virtual std::string allInfo() const;
 virtual void update();
 void Set_Arret(){
    _NbArret++;
 }
 private:
 size_t _NbArret;
 
 
};