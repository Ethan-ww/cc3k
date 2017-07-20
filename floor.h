//
//  floor.hpp
//  cc3k
//
//  Created by j539li on 2017-07-17.
//  Copyright © 2017 j539li. All rights reserved.
//

#ifndef floor_hpp
#define floor_hpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "character.h"
#include "item.h"
#include "cell.h"

class Floor {
    int width = 80;
    int height = 25;
    //Cell grid[width][height];
    //Cell** grid;
    vector<vector<Cell>> grid;
    vector<vector<Cell*>> chamber;
    vector<Cell> availableCell;
public:
    Floor();
    Floor(std::string,int);
    void set_chamber();
    void spawn_player(std::string);
    void spawn_potions();
    void spawn_enemies();
    void move_enemy();
    void move_player();
    void DisplayMap();
};

#endif /* floor_hpp */
