#include<iostream>
#include<cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include "Jeu.hh"

extern string str1;
extern string str2;
int Jeu::compt_J1=0;
int Jeu::compt_J2=0;
using namespace std;


Jeu::Jeu(){
    c1= {"mexico48.png","france48.png","italy48.png","germany48.png","india48.png","brazil48.png","usa48.png","morocco48.png","tunisia48.png","japan48.png"}; 
    c2={"back1.png","back2.png","back3.png","back4.png"};
    cout<<"Bienvenu au PHF (Pong Hockey Football)"<<endl;  
    
}

bool Jeu::afficher_regles(){
    int mode;
    cout<<"Souhaitez vous l'affichage des règles du jeu : 1 = Oui, 2 = Non "<<endl;
    cin>>mode;
    if(mode==1)
        return true;
    else
        return false;

}

void Jeu::Choix_Joueur1(){
    string pays;
    string temp;
    string temp2;
    cout<<"Joueur 1 : Taper le pays que vous voulez représenter parmi : mexico, france, italy, germany, india, brazil, usa, morocco, tunisia, japan "<<endl;
    cin>>pays;
    temp2=pays;
    pays+="48.png";
    size_t i;
    for (i=0; i<c1.size(); i++)
    {
      temp=string(c1[i]);  
      bool isEqual = temp == pays; 
      if (isEqual) {
            pays2+=temp2;
            pays2+=".png";
            str1+="pays/";
            str1+=pays;   
    }
    
    }
}

int Jeu::Choix_Mode(){
    int mode;
    cout<<"Choisir mode de jeu parmi : 1 = Mode Normal , 2 = Mode Fun "<<endl;
    cin>>mode;
    return mode;
}

void Jeu::Choix_Joueur2(){
    string pays;
    string temp;
    string temp2;
    cout<<"Joueur 2 : Taper le pays que vous voulez représenter parmi : mexico, france, italy, germany, india, brazil, usa, morocco, tunisia, japan"<<endl;
    cin>>pays;
    temp2=pays;
    pays+="48.png";
    size_t i;
    for (i=0; i<c1.size(); i++)
    {
      temp=string(c1[i]);  
      bool isEqual = temp == pays; 
      if (isEqual) {
            pays3+=temp2;
            pays3+=".png";
            str2+="pays/";
            str2+=pays;   
    }
    
    }
}

void Jeu::Choix_Map(){
     string pays;
    string temp;
    
    cout<<"Choisir map parmi : back1, back2, back3, back4"<<endl;
    cin>>pays;
    pays+=".png";
    
    size_t i;
    for (i=0; i<c2.size(); i++)
    {
      temp=string(c2[i]);  
      bool isEqual = temp == pays; 
      if (isEqual) {
            map+=pays;
    }
    
    }

}

void Jeu::start(Ballon &ball, sf::RenderWindow &window,int gameStartDelay,int gameStartCounter){
           
        
        if (gameStartCounter >= gameStartDelay && !ball.getballLaunched())
        {
            ball.setballLaunched(true);
            float randomX = ((rand() % 2) == 0) ? -1 : 1;
            float randomY = ((rand() % 2) == 0) ? -1 : 1;
            sf::Vector2f ballVelocity(randomX, randomY);
            ball.setBallVelocity(ballVelocity);
        }
        // Gérer les événements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
}


bool Jeu::check_goal(Ballon &ball,Joueur &player,Joueur &player1,Joueur &player2,Joueur &player3,sf::RenderWindow &window,int &gameStartCounter){

        //Verification si le ballon est dans la zone de but
        float ballWidth = ball.getsprite().getGlobalBounds().width;
        if (ball.getX() < 0 && (ball.getY() >170 && ball.getY() < 290)) {
            ball.init_ball();
            gameStartCounter = 0;
            ball.setBallVelocity(sf::Vector2f(0,0));
            player.Set_velocity(sf::Vector2f(0,0));
            player1.Set_velocity(sf::Vector2f(0,0));
            player2.Set_velocity(sf::Vector2f(0,0));
            player3.Set_velocity(sf::Vector2f(0,0));
            player.setPosition(0, 200);
            player1.setPosition(250, 200);
            player2.setPosition(721, 200);
            player3.setPosition(400, 200);
            compt_J2++;
            cout<< " ______________________________" << endl;
            cout << "|                              |" <<endl;
            cout << " " << "Equipe 1" << "|" << to_string(compt_J1) << "  |  " <<to_string(compt_J2) << "|" << "Equipe 2" << "   " << endl;
            cout << "|______________________________|" << endl;
            return true;
        }

        if (ball.getX() > window.getSize().x - ballWidth && (ball.getY() >170 && ball.getY() < 290)) {
            ball.init_ball();
            gameStartCounter = 0;
            ball.setBallVelocity(sf::Vector2f(0,0));
            player.Set_velocity(sf::Vector2f(0,0));
            player1.Set_velocity(sf::Vector2f(0,0));
            player2.Set_velocity(sf::Vector2f(0,0));
            player3.Set_velocity(sf::Vector2f(0,0));
            player.setPosition(0, 200);
            player1.setPosition(250, 200);
            player2.setPosition(721, 200);
            player3.setPosition(400, 200);
            compt_J1++;
            cout<< " ______________________________" << endl;
            cout << "|                              |" <<endl;
            cout << "| " << "Equipe 1" << "|" << to_string(compt_J1) << "  |  " <<to_string(compt_J2) << "|" << "Equipe 2" << "   " << endl;
            cout << "|______________________________|" << endl;
            return true;
        }
        return false;
}


std::ostream &operator<<(std::ostream &os, const Jeu &jeu) {

     ifstream fichier("rules.txt");
    
    if(fichier)
   {
      string ligne; 
      while(getline(fichier, ligne)) 
         os << ligne << endl;
   }
   else
      os << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

    return os;
}