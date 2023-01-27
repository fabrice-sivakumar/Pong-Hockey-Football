#include "joueur.hh"


using namespace std;

bool Joueur::joueuractif1 = true;
bool Joueur::joueuractif2 = true;
int Joueur::_nbJoueur = 1;

Joueur::Joueur(string prenom,string nom,size_t x, size_t y,string image):_prenom(prenom),_nom(nom),_x(x),_y(y),_image(image){
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
  }

void Joueur::borderlimits(const sf::RenderWindow &window){        
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
            sprite.setPosition(playerPos.x, window.getSize().y - sprite.getGlobalBounds().height);
}

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
