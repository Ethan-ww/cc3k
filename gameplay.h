//
//  gameplay.hpp
//  item
//
//  Created by 姚博伦 on 2017/7/19.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#ifndef gameplay_h
#define gameplay_h

#include <stdio.h>
#include "floor.h"

class Gameplay{
    bool is_hostile;
    char champion;
    Character *pc;
    int curr;
    string file="";
    Floor* v[5];
public:
    Gameplay();
    Gameplay(string file);
    int create_game();
    string move(string direction);
    void setplayer();
    void displayall(string info);
    ~Gameplay();
};
#endif /* gameplay_h */
