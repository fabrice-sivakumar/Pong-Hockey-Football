#pragma once
#include "goal.hh"
#include <string>
#include "joueur.hh"
using namespace std;

class Goalkeeper_Hero: public Goalkeeper{
 public:
 Goalkeeper_Hero(string prenom,string nom,float x, float y,string image);
 std::string allInfo() const;
 void update();
size_t get_spe(){
    return _spe;
 }
 private:
std::string _capacite;
size_t _spe;

 
};
