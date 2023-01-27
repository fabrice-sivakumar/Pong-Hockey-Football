#include "goal.hh"
using namespace std;


Goalkeeper::Goalkeeper(string prenom,string nom,float x, float y, string image):Joueur(prenom,nom,x,y,image)
{
  _poste="GARDIEN";
  _NbArret=0;
}


std::string Goalkeeper::allInfo() const
{
  std::string str;
  str+= Joueur::allInfo();
  str+=",";
  str+=_poste;
  str+=", Nombre d'arrêt : ";
  str+=std::to_string(_NbArret);
  return str;
}


void Goalkeeper::update(){
      // Appliquer l'accélération suivant les touches pressées
        if (_numero%2==0)
            {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& joueuractif1==false)
                velocity.y -= acceleration;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& joueuractif1==false)
                velocity.y += acceleration;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)&& joueuractif1==false)
            {
                joueuractif1=true;
                velocity = sf::Vector2f(0, 0);
            }
            }
        else
            {
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)&& joueuractif2==false)
                velocity.y -= acceleration;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& joueuractif2==false)
                velocity.y += acceleration;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)&& joueuractif2==false)
            {
                joueuractif2=true;
                velocity = sf::Vector2f(0, 0);
            }
            }
            // Limiter la vitesse maximale
            if (velocity.x > maxSpeed)
                velocity.x = maxSpeed;
            if (velocity.x < -maxSpeed)
                velocity.x = -maxSpeed;
            if (velocity.y > maxSpeed)
                velocity.y = maxSpeed;
            if (velocity.y < -maxSpeed)
                velocity.y = -maxSpeed;

            //float GoalHeight = sprite.getGlobalBounds().height;
            //Limiter la position du gardien à ses cages
            if(_y>250)
                sprite.setPosition(_x, 250);
            if(_y<168)
                sprite.setPosition(_x, 168);
            // Appliquer la vitesse à la position
            sprite.move(velocity);
    }
