//
//  human.cpp
//  cc3k
//
//  Created by w43wei on 2017-07-19.
//  Copyright © 2017 w43wei. All rights reserved.
//

#include "human.h"
#include "character.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

// default ability of human: 140 HP, 20 Atk, 20 Def
Human::Human(): Enemy(140, 20, 20){
    this->type="human";
}

string Human::attack(Character *pc){
    int damage=(int)(atk*(100.0/(100.0+pc->getDef())));
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

Human::~Human(){}
