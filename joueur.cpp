#include "joueur.hh"


using namespace std;

bool Joueur::joueuractif1 = true;
bool Joueur::joueuractif2 = true;
int Joueur::_nbJoueur = 1;

std::string Joueur::allInfo() const
{
  string str;
  str+=_prenom;
  str+= " " +_nom;
  return str;
}


std::ostream& operator<<(std::ostream& os, const Joueur &e)
{
  os << e.allInfo();
  return os;
}