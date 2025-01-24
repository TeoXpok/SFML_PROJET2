#pragma once

#include <fstream>

#include "Pillar.h"  
#include "Floor.h"

using namespace sf;
using namespace std;

class Map {
public:

    vector<Pillar*> pillars;  
    vector<Floor*> floors;   
    vector<Potion*> potions;
    vector<PatrollingEnemy*> zombies;
    Player* player; 


    PatrollingEnemy* zombos = new PatrollingEnemy(500, 500, "ZZZZZZZZZZ                   DDDDDDDDDD             QQQQQQQQQQ           SSSSSSSSSS               ");
    
    Map(Player* p) : player(p) {}

    // Méthode pour charger la carte depuis un fichier
    void loadMap(const string& fileName) {
        ifstream file(fileName);
        // X -> 20
        // Y -> 16
        if (!file.is_open()) {
            cerr << "Impossible d'ouvrir le fichier " << fileName << endl;
            return;
        }

        string line;
        int y = 0;

        // Lire chaque ligne du fichier
        while (getline(file, line)) {
            for (int x = 0; x < line.size(); ++x) {
                char tile = line[x];

                // Crée un objet en fonction du caractère rencontré
                if (tile == '#') {
                    // Crée un Pillar
                    Pillar* pillar = new Pillar(x * 50, y * 50+150, player);  // Positionne à x * 50, y * 50 (par exemple)
                    pillars.push_back(pillar);  // Ajoute le Pillar à la liste
                }
                else if (tile == ' ') {
                    // Crée un Floor
                    Floor* floor = new Floor(x * 50, y * 50+200);  // Même chose pour Floor
                    floors.push_back(floor);  // Ajoute le Floor à la liste
                }
                else if (tile == 'P') {
                    // Crée un Floor
                    Floor* floor = new Floor(x * 50, y * 50 + 200);  // Même chose pour Floor
                    floors.push_back(floor);  // Ajoute le Floor à la liste
                    Potion* potion = new Potion(x * 50, y * 50 + 200, player);  // Même chose pour Floor
                    potions.push_back(potion);  // Ajoute le Floor à la liste
                }
                else if (tile == 'Z') {
                    // Crée un Floor
                    Floor* floor = new Floor(x * 50, y * 50 + 200);  // Même chose pour Floor
                    floors.push_back(floor);  // Ajoute le Floor à la liste
                    PatrollingEnemy* zombos = new PatrollingEnemy(500, 500, "ZZZZZZZZZZ                   DDDDDDDDDD             QQQQQQQQQQ           SSSSSSSSSS               ");  // Même chose pour Floor
                    zombies.push_back(zombos);  // Ajoute le Floor à la liste
                }
            }
            ++y;
        }

        file.close();  // Ferme le fichier
    }


    // Méthode pour mettre à jour la carte (si nécessaire)
    void update(RenderWindow& window) {
        for (Floor* floor : floors) {
            floor->update(window, player->sprite);
        }

        for (Pillar* pillar : pillars) {
            pillar->update(window, player->sprite);
        }

        
        for (auto& potion : potions) {
            potion->update(window, player->sprite);
        }

        for (auto it = potions.begin(); it != potions.end(); ) {
            if ((*it)->used) {
                delete* it;
                it = potions.erase(it);
            }
            else {
                ++it;
            }
        }
        for (auto& zombie : zombies) {
            zombie->update(window, player->sprite);
        }
    }

};

