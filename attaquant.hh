#pragma once
#include<iostream>
#include<cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include "joueur.hh"

using namespace std;

class Attaquant: public Joueur{
 public:
  Attaquant(string prenom,string nom,float x, float y,string image);
 virtual std::string allInfo() const;
 virtual void update();
  void SetBut(){
  _NbBut++;
 };
 size_t GetBut(){
  return _NbBut;
 }
 protected:
 std::string _poste;
  size_t _NbBut;
 
};

/*std::ostream& operator<<(std::ostream& os, const Attaquant &e)
{
  os << e.allInfo();
  return os;
}*/
