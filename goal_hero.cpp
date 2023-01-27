#include "goal_hero.hh"
#include "joueur.hh"
using namespace std;
extern string str1;
extern string str2;


Goalkeeper_Hero::Goalkeeper_Hero(string prenom,string nom,float x, float y,string image):Goalkeeper(prenom,nom,x,y,image)
{
    _capacite="Peut grossir";
    _spe=1;
}

std::string Goalkeeper_Hero::allInfo() const
{
  std::string str;
  str+= Goalkeeper::allInfo();
  str+=", ";
  str+=_capacite;
  return str;
}



void Goalkeeper_Hero::update() {

        Goalkeeper::update();
        //
        static int temps_de_chargement =0; //max 600
        static int temps_de_spe =0; // max 600

        if(_numero%2==0){
        if(_spe==2){
            temps_de_spe++;
            if(temps_de_spe==1000){
                _spe=0;
                temps_de_spe=0;
            }
        }else if(_spe==0){
           
            temps_de_chargement++;
            if(temps_de_chargement==1500){
                temps_de_chargement=0;
                _spe=1;
            }
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)&&(_spe==1)&&(joueuractif1==false)){
            

            // Charger l'image du joueur
            if (!texture.loadFromFile(str2)) {
                std::cout << "Erreur lors du chargement de l'image " << std::endl;
            }

            // Initialiser le sprite du joueur
        
        
            sprite.setTexture(texture);
            sprite.setPosition(_x, _y);

            // Initialiser la vitesse et l'accélération du joueur
            velocity = sf::Vector2f(0, 0);
            acceleration = 0.1;
            maxSpeed = 1.0;
        
            _spe=2;
            
            }
            
        if((_spe==0)&&(temps_de_chargement==1)){
              if (!texture.loadFromFile(_image)) {
            std::cout << "Erreur lors du chargement de l'image " << std::endl;
        }

        // Initialiser le sprite du joueur
        sprite.setTexture(texture);
        sprite.setPosition(_x, _y);

        // Initialiser la vitesse et l'accélération du joueur
        velocity = sf::Vector2f(0, 0);
        acceleration = 0.1;
        maxSpeed = 1.0;
        }
        
        // Appliquer l'accélération suivant les touches pressées
        }else{
            if(_spe==2){
            temps_de_spe++;
            if(temps_de_spe==1000){
                _spe=0;
                temps_de_spe=0;
            }
        }else if(_spe==0){
           
            temps_de_chargement++;
            if(temps_de_chargement==1500){
                temps_de_chargement=0;
                _spe=1;
            }
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&(_spe==1)&&(joueuractif2==false)){
            

            // Charger l'image du joueur
            if (!texture.loadFromFile(str1)) {
                std::cout << "Erreur lors du chargement de l'image" << std::endl;
            }

            // Initialiser le sprite du joueur
        
        
            sprite.setTexture(texture);
            sprite.setPosition(_x, _y);

            // Initialiser la vitesse et l'accélération du joueur
            velocity = sf::Vector2f(0, 0);
            acceleration = 0.1;
            maxSpeed = 1.0;
        
            _spe=2;
            
            }
            
        if((_spe==0)&&(temps_de_chargement==1)){
              if (!texture.loadFromFile(_image)) {
            std::cout << "Erreur lors du chargement de l'image " << std::endl;
        }

        // Initialiser le sprite du joueur
        sprite.setTexture(texture);
        sprite.setPosition(_x, _y);

        // Initialiser la vitesse et l'accélération du joueur
        velocity = sf::Vector2f(0, 0);
        acceleration = 0.1;
        maxSpeed = 1.0;
        }
         
        }
    }

    
  