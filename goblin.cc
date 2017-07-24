//
//  goblin.cpp
//  cc3k
//
//  Created by w43wei on 2017-07-17.
//  Copyright © 2017 w43wei. All rights reserved.
//

#include "goblin.h"
#include "character.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

// default ability of goblin: 110 HP, 15 Atk, 20 Def
Goblin::Goblin(): Player(110, 15, 20){
    this->type="goblin";
}

string Goblin::attack(Character *ec){
    int damage=(int)(atk*(100.0/(100.0+ec->getDef())));
    int newHp;
    if(ec->getHp()-damage<0){ // hp cannot be zero
        newHp=0;
    }else{
        newHp=ec->getHp()-damage;
    }
    ostringstream ss;
    if(rand()%100 < 50 && ec->getType()=="halfling"){ // 50% chance miss
        return "PC misses the attack on halfling.";
    }
    
    // other races
    addGold(5); // steal gold
    ec->setHp(newHp);
    ss << "PC deals " << damage << " damage to " << ec->getType()
    << " (" << ec->getHp() << " HP).";
    return ss.str();
}

void Goblin::reset(){
    setAtk(15);
    setDef(20);
}

Goblin::~Goblin(){}

