#include "attaquant_hero.hh"
#include "joueur.hh"
using namespace std;


Attaquant_Hero::Attaquant_Hero(string prenom,string nom,float x, float y,string image):Attaquant(prenom,nom,x,y,image)
{

  _capacite="Attire la balle à lui";
  _spe=1;
}


std::string Attaquant_Hero::allInfo() const
{
  std::string str;
  str+= Attaquant::allInfo();
  str+=",";
  str+=_capacite;
  return str;
}


void Attaquant_Hero::update(Ballon &ball) {

        Attaquant::update();
        static int temps_de_chargement =0; //max 600
       

        //capacité de ballon
        if(_numero%2==0){
             if(_spe==0){
           
            temps_de_chargement++;
            if(temps_de_chargement==1000){
                temps_de_chargement=0;
                _spe=1;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)&&(joueuractif1==true)&&(_spe==1)){
            distance(ball);
            _spe=0;
        }
        }else{
            if(_spe==0){
           
            temps_de_chargement++;
            if(temps_de_chargement==1500){
                temps_de_chargement=0;
                _spe=1;
            }
        }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&(joueuractif2==true)&&(_spe==1)){
            distance(ball);
            _spe=0;
            }
        }
    }

void Attaquant_Hero::distance(Ballon &ball){

    float y = ball.getY();
    float x = ball.getX();
   
    x=_x-x;
    y=_y-y;

     sf::Vector2f velocite(x,y);
    ball.setBallVelocity(velocite);

}