//
//  orcs.cpp
//  cc3k
//
//  Created by w43wei on 2017-07-19.
//  Copyright © 2017 w43wei. All rights reserved.
//

#include "orcs.h"
#include "character.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

// default ability of orcs: 180 HP, 30 Atk, 25 Def
Orcs::Orcs(): Enemy(180, 30, 25){
    this->type="orc";
    if(rand()%100 < 50){ // randomly generate gold
        addGold(1);
    }else{
        addGold(2);
    }
}

string Orcs::attack(Character *pc){
    int damage=(int)(atk*(100.0/(100.0+pc->getDef())));
    if(pc->getType()=="goblin") damage=(int)damage*1.5; // does 50% more damage to goblins
    int newHp;
    if(pc->getHp()-damage<0){ // hp cannot be zero
        newHp=0;
    }else{
        newHp=pc->getHp()-damage;
    }
    ostringstream ss;
    if(rand()%100 < 50){ // 50% chance miss
        return type+" misses the attack on PC.";
    }else{
        // don't miss
        pc->setHp(newHp);
        ss << type << " deals " << damage << " damage to PC.";
        return ss.str();
    }
    
}

Orcs::~Orcs(){}
