#include "attaquant.hh"
using namespace std;


Attaquant::Attaquant(string prenom,string nom,float x, float y,string image):Joueur(prenom,nom,x,y,image)
{
  _poste="ATTAQUANT";
  _NbBut=0;
}


std::string Attaquant::allInfo() const
{
  std::string str;
  str+= Joueur::allInfo();
  str+=",";
  str+=_poste;
  str+=", Nombre de but(s) : ";
  str+=std::to_string(_NbBut);
  return str;
}

void Attaquant::update() {
       
        // Appliquer l'accélération suivant les touches pressées
        if (_numero%2==0)
        {
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && joueuractif1==true)
              velocity.y -= acceleration;
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& joueuractif1==true)
              velocity.y += acceleration;
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& joueuractif1==true)
              velocity.x -= acceleration;
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& joueuractif1==true)
              velocity.x += acceleration;
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)&& joueuractif1==true)
          {
              joueuractif1=false;
              velocity = sf::Vector2f(0, 0);
          }
        }
        else
        {
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && joueuractif2==true)
              velocity.y -= acceleration;
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& joueuractif2==true)
              velocity.y += acceleration;
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)&& joueuractif2==true)
              velocity.x -= acceleration;
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& joueuractif2==true)
              velocity.x += acceleration;
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)&& joueuractif2==true)
            {
                joueuractif2=false;
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
            
        if((_x>626)&&(_y>125)&&(_y<290)){
           // cout<<_x<<" "<<_y<<endl;
             if((_y<=126)&&(_y>0)){
            sprite.setPosition(_x-1, 124);
            velocity.y=0;
             }
            else if((_y>=289)&&(_y<464)){
            sprite.setPosition(_x-1, 291);
            velocity.y=0;
            }
            else
            sprite.setPosition(626,_y);
        }
        if((_x<49)&&(_y>125)&&(_y<290)){
           // cout<<_x<<" "<<_y<<endl;
             if((_y<=126)&&(_y>0)){
            sprite.setPosition(_x+1, 124);
            velocity.y=0;
             }
            else if((_y>=289)&&(_y<464)){
            sprite.setPosition(_x+1, 291);
            velocity.y=0;
            }
            else
            sprite.setPosition(49,_y);
        }

        // Appliquer la vitesse à la position
         sprite.move(velocity);
}
