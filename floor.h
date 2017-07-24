//
//  floor.hpp
//  cc3k
//
//  Created by j539li on 2017-07-17.
//  Copyright © 2017 j539li. All rights reserved.
//

#ifndef floor_h
#define floor_h

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "character.h"
#include "item.h"
#include "cell.h"
#include "enemy.h"
#include "player.h"
#include "treasure.h"
#include "potion.h"
#include "dragon.h"
#include "drow.h"
#include "dwarf.h"
#include "elf.h"
#include "goblin.h"
#include "halfling.h"
#include "merchant.h"
#include "orcs.h"
#include "shade.h"
#include "troll.h"
#include "vampire.h"
#include "human.h"

class Floor {
    int width = 80;
    int height = 25;
    vector<vector<Cell>> grid;
    vector<vector<Cell*>> chamber;
    vector<Character*> listofenmey;
    vector<Potion*> listofpotion;
    vector<Treasure*> listoftreasure;
    bool is_drow=false;
    Cell *newcord(string dir, int x, int y);
    string attackplayer(Character *nc, Character *player);
public:
    int playerX;
    int playerY;
    Floor();
    Floor(std::string,int,Character*);
    void set_chamber();
    void spawn_player(Character*);
    void spawn_potions();
    void spawn_enemies();
    void move_enemy();
    string move_player(string);
    void DisplayMap();
    void spawn_gold();
    bool is_valid(int,int);
    void set_isdrown(bool);
    void swap(Cell*,Cell*);
    Cell* getCell(int x, int y);
    //Cell* getPlayer();
    string usepotion(string dir);
    string attackenemy(string dir, bool& is_hostile);
    string attackplayer(bool is_hostile);
    ~Floor();
};

#endif /* floor_hpp */
