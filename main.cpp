#include<iostream>
#include<cstdlib>
#include <string>
#include <cstring> 
#include <sstream>
#include <vector>
#include<list>
#include <cassert>


#include "ballon.hh"
#include "attaquant_hero.hh"
#include "goal_hero.hh"
#include "attaquant_normal.hh"
#include "goal_normal.hh"
#include "Jeu.hh"
#include <SFML/Graphics.hpp>



using namespace std;
using namespace sf;
string str1;
string str2;
void setVisible(sf::Sprite &sprite,bool visible)
{
    if (visible)
        sprite.setColor(sf::Color::White);
    else
        sprite.setColor(sf::Color::Transparent);
}


int main()
{

//Partie test unitaire
Attaquant_Normal attaquant("KyKy","Bondy",250,200,"pays/france.png");
//Test Attaquant
cout << "Test d'un attaquant" << ::endl;
attaquant.SetBut();
assert(attaquant.GetBut() == 1);
attaquant.Set_velocity(sf::Vector2f(1,1));
assert(attaquant.Get_velocity() == sf::Vector2f(1,1));
assert(attaquant.getX() == 250);
assert(attaquant.getY() == 200);
attaquant.setPosition(300,310);
assert(attaquant.getX() == 300);
assert(attaquant.getY() == 310);
assert(attaquant.getNbJoueur() == 2);
cout << "Test d'un attaquant fini'" << ::endl;
//Test Goal

cout << "Test d'un goal'" << ::endl;
Goalkeeper_Normal goal1("KyKy","Bondy",250,200,"pays/france.png");
assert(goal1.getNbJoueur() == 3);
assert(attaquant.getNbJoueur() == 3);
assert(goal1.getX() == 250);
assert(goal1.getY() == 200);
cout << "Test d'un goal fini'" << ::endl;


// Partie Jeu
 Jeu jeu;
 if (jeu.afficher_regles())
    cout<<jeu<<endl;

 jeu.Choix_Joueur1();
 jeu.Choix_Joueur2();
 jeu.Choix_Map();
 int choice=jeu.Choix_Mode();
 RenderWindow window(VideoMode(721,464, 32),
"PHF ");

    // Charger l'image du logo "GOAL"
    sf::Texture goalTexture;
    if (!goalTexture.loadFromFile("goal.png"))
    {
        // Gérer le cas où l'image ne peut pas être chargée
        std::cout << "Erreur lors du chargement de l'image goal.png" << std::endl;
        return 1;
    }

    // Créer le sprite du logo "GOAL"
    sf::Sprite goal(goalTexture);
    goal.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    setVisible(goal,false);

    int goalCounter = 0;
    int goalDelay = 100;

    // Charger l'image de fond
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("back/"+jeu.Get_Map()))
    {
        // Gérer le cas où l'image ne peut pas être chargée
        std::cout << "Erreur lors du chargement de l'image background.png" << std::endl;
        return 1;
    }

    // Créer le sprite de fond
    sf::Sprite background(backgroundTexture);


    
    //Charger le joueur

    Goalkeeper_Hero player("KyKy","Bondy",0,200,"pays/"+jeu.Get_Pays1());
    Goalkeeper_Hero player2("KyKy","Bondy",721,200,"pays/"+jeu.Get_Pays2());
    Attaquant_Hero player1("kk","jj",250,200,"pays/"+jeu.Get_Pays1());
    Attaquant_Hero player3("kk","jj",400,200,"pays/"+jeu.Get_Pays2());


    Goalkeeper_Normal player_normal("KyKy","Bondy",0,200,"pays/"+jeu.Get_Pays1());
    Goalkeeper_Normal player2_normal("KyKy","Bondy",721,200,"pays/"+jeu.Get_Pays2());
    Attaquant_Normal player1_normal("kk","jj",250,200,"pays/"+jeu.Get_Pays1());
    Attaquant_Normal player3_normal("kk","jj",400,200,"pays/"+jeu.Get_Pays2());



    Ballon ball(360, 230);

    int gameStartDelay = 400;
    int gameStartCounter = 0;
    
    // Boucle principale
    while (window.isOpen())
    {
        if (gameStartCounter < gameStartDelay)
            gameStartCounter++;
        
        jeu.start(ball,window,gameStartDelay,gameStartCounter);
        if (choice==2)
        {
            player.borderlimits(window);
            player1.borderlimits(window);
            player2.borderlimits(window);
            player3.borderlimits(window);
        }
        else
        {
            player_normal.borderlimits(window);
            player1_normal.borderlimits(window);
            player2_normal.borderlimits(window);
            player3_normal.borderlimits(window);
        }

        if (gameStartCounter >= gameStartDelay)
        {
            // Mettre à jour le joueur
            if (choice==2)
            {
                player.update();
                player2.update();
                player1.update(ball);
                player3.update(ball);
            }
            else
            {
                player_normal.update();
                player2_normal.update();
                player1_normal.update();
                player3_normal.update();
            }

        }
      
         // Appliquer la vitesse au ballon
        ball.balllimit(window);
        ball.update();
        // Gérer les collisions
        if (choice==2)
        {
            ball.manage_collision(player);
            ball.manage_collision(player1);
            ball.manage_collision(player2);
            ball.manage_collision(player3);
        }
        else
        {
            ball.manage_collision(player_normal);
            ball.manage_collision(player1_normal);
            ball.manage_collision(player2_normal);
            ball.manage_collision(player3_normal);
        }
        if (choice==2)
        {
            if (jeu.check_goal(ball,player,player1,player2,player3,window,gameStartCounter))
            {
                goalCounter=0;
                gameStartCounter=0;
                setVisible(goal,true);
            }
        }
        else
        {
            if (jeu.check_goal(ball,player_normal,player1_normal,player2_normal,player3_normal,window,gameStartCounter))
            {
                goalCounter=0;
                gameStartCounter=0;
                setVisible(goal,true);
            }
        }

        if (goalCounter<200)
            goalCounter++;
        if (goalCounter >= goalDelay)
        {
            setVisible(goal,false);
        }

        // Effacer l'écran
        window.clear(sf::Color::White);

        // Dessiner le fond
        window.draw(background);

        // Dessiner le joueur
        if (choice==2)
        {
            window.draw(player.getSprite());
            window.draw(player1.getSprite());
            window.draw(player2.getSprite());
            window.draw(player3.getSprite());
        }
        else
        {
            window.draw(player_normal.getSprite());
            window.draw(player1_normal.getSprite());
            window.draw(player2_normal.getSprite());
            window.draw(player3_normal.getSprite());
        }

        window.draw(ball.getsprite());
        window.draw(goal);

        // Afficher l'écran
        window.display();
    }

    return 0;
}
