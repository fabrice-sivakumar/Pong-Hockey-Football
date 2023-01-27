# Pong-Hockey-Football

Le jeu Pong-Hockey-Football (PHF) est un jeu comme son nom l'indique un mixte entre le hockey sur table, le pong et le football. C'est un jeu qui se joue à 2 localement sur une même machine. Le but du jeu est de marquer 3 buts avant son adversaire. Dans ce jeu, chaque joueur contrôle un gardien et un attaquant. Il y a deux modes: un mode Normal où le joue se déroule classiquement et un autre mode Fun où l'attaquant et le gardien possède une capacité spéciale. 

## Installation 
Pour jouer au jeu, il faut au préalable installer la librairie sfml en utilisant la commande ci-dessous sur un terminal Linux:

`sudo apt-get install libsfml-dev`

## Commandes
***Joueur 1(Joueur de gauche):***

Changer de l'attaquant au gardien :V

Changer du gardien à l'attaquant au gardien:C

Haut: Z

Bas:S

Droite:D

Gauche:Q

Coup spécial:W

***Joueur 2(Joueur de droite):***

Changer de l'attaquant au gardien :K

Changer du gardien à l'attaquant au gardien:L

Haut: Flèche haut

Bas: Flèche bas

Droite: Flèche droite

Gauche: Flèche gauche

Coup spécial: M


Vous pourrez aussi avoir accès aux règles du jeu et aux commandes dans le fichier `rules.txt` et il sera aussi proposé à chaque partie de voir les règles du jeu.

## Jouabilité
Après avoir téléchargé le dossier et la librairie SFML, il suffit de faire un `make` puis exécuter l'exécutable: `./app`
Différents choix et questions seront posés sur le terminal pour afficher ou pas les règles,choisir le pays représenté et choisir le terrain parmi une liste.

## Tests
Divers tests sur les gardiens et les attaquants sont effectuées au début du programme grâce à des assert pour vérifier le bon fonctionnement des fonctions tels que les setters et getters.

## Auteurs

- [@fabrice-sivakumar](https://github.com/fabrice-sivakumar)
- [@VictorEI-SE](https://github.com/VictorEI-SE)
