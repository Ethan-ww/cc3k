//
//  gameplay.cpp
//  item
//
//  Created by 姚博伦 on 2017/7/19.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#include "gameplay.h"
#include <ctype.h>
#include <sstream>
#include <iostream>
using namespace std;
Gameplay::Gameplay(): is_hostile{false}, champion{' '}, pc{nullptr}, curr{0}{
    //Floor f1;
    //Floor f2;
    //Floor f3;
    //Floor f4;
    //Floor f5;
    //v.push_back(Floor());
    //v.push_back(Floor());
    //v.push_back(Floor());
    //v.push_back(Floor());
    //v.push_back(Floor());
    for (int i = 0; i < 5; i++) {
        this->v[i]= new Floor();
    };
    
}

//Gameplay::Gameplay(string file): is_hostile{false}, champion{' '}, curr{0}{
//    Floor f1(file,1);
//    Floor f2(file,2);
//    Floor f3(file,3);
//    Floor f4(file,4);
//    Floor f5(file,5);

//    v.push_back(f1);
//    v.push_back(f2);
//    v.push_back(f3);
//    v.push_back(f4);
//    v.push_back(f5);
//}
//



void Gameplay::setplayer(){
    switch(champion){
        case 's':{
            pc=new Shade();
            break;
        }
        case 'd':{
            pc=new Drow();
            v[curr]->set_isdrown(true);
            break;
        }
        case 'v':{
            pc=new Vampire();
            break;
        }
        case 'g':{
            pc=new Goblin();
            break;
        }
        case 't':{
            pc=new Troll();
            break;
        }
        default:
            string s = "bad enter";
            throw s;
            break;
    }
    v[curr]->spawn_player(pc);
    v[curr]->spawn_potions();
    v[curr]->spawn_gold();
    v[curr]->spawn_enemies();

}

int Gameplay::create_game(){
    cout << "choose a champion" << endl;
    while(true){
        if (cin >> champion){
            try{
                setplayer();
            } catch(string s){
                cout << s << endl;
            }
            break;
        } else {
            cin.clear();
            cin.ignore();
        }
    }
    //displayall("");

    string s="";
    string cmd;
    bool mode = true; // true means normal mode, flase otherwise
    char c;
    int i = 0;
    while(true){
        string info = "";
        if(cin >> cmd){
            if(cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" || cmd == "ne" ||
               cmd == "nw" || cmd == "se" || cmd == "sw"){
                // move player
                info=v[curr]->move_player(cmd);
                if( info == "true"){ // already move here
                    if(curr == 4){
                        displayall("Game win!");
                        cin >> i;
                        return i;
                        // win the game
                    } else {
                        info = "PC moves to the next floor!";
                        displayall(info);
                        ++curr;
                        pc->reset();
                        v[curr]->spawn_player(pc);
                        v[curr]->spawn_potions();
                        v[curr]->spawn_gold();
                        v[curr]->spawn_enemies();
                        continue;
                        // moves to next floor
                    }
                }
                
                if(mode){
                    v[curr]->move_enemy();
                }
                info = v[curr]->attackplayer(is_hostile); // enemys around attack player
                if(pc->getHp()==0){
                    displayall("PC is dead!");
                    cin >> i;
                    return i;
                }
                displayall(info);
                
            } else{
                istringstream ss{cmd};
                if(cmd.length()!=1){
                    continue;
                }
                
                ss >>c;
                switch (c) {
                    case 'u': // use potion
                        cin >> cmd; // input direction
                        info = v[curr]->usepotion(cmd);
                        // info store the information of using potion
                        if(pc->getHp()==0){
                            displayall("PC is dead!");
                            cin >> i;
                            return i;
                        }
                    
                        if(mode){
                            v[curr]->move_enemy();
                        }
                        info += " ";
                        info += v[curr]->attackplayer(is_hostile); // enemys around attack player
                        if(pc->getHp()==0){
                            displayall("PC is dead!");
                            cin >> i;
                            return i;
                        }
                        displayall(info);
                        break;
                    case 'a':
                        cin >> cmd;
                        info = v[curr]->attackenemy(cmd,is_hostile);
                        info += v[curr]->attackplayer(is_hostile);
                        if(pc->getHp()==0){
                            displayall("PC is dead!");
                            cin >> i;
                            return i;
                        }
                        
                        if(mode){
                            v[curr]->move_enemy();
                        }
                        displayall(info);
                        break;
                    case 'f':
                        if(mode){
                            mode = false;
                            info = "Change to static mode";
                        } else {
                            mode = true;
                            info = "Change to normal mode";
                        }
                        displayall(info);
                    case 'r':
                        return 1;
                    case 'q':
                        return 2;
                    default:
                        cin.clear();
                        cin.ignore();
                }
            }
        } else{
            cin.clear();
            cin.ignore();
            continue;
        }
    }
}

void Gameplay::displayall(string info){
    v[curr]->DisplayMap();
    string player;
    switch(champion){
        case 's':
            player = "Shade";
        case 'd':
            player = "Drow";
        case 'v':
            player = "Vampire";
        case 'g':
            player = "Goblin";
        case 't':
            player = "Troll";
        default:
            break;
    }
    cout << "Race: " << player << " Gold: " << pc->getGold() << endl;
    cout << "Hp: " << pc->getHp() <<endl;
    cout << "Atk: " << pc->getAtk() <<endl;
    cout << "Def: " << pc->getDef() <<endl;
    if(info == "PC is dead!" || info == "Game win!"){
        info = info + "1-playagain \n2-quit";
    }
    cout <<"Action: " << info<< endl;
}

Gameplay::~Gameplay(){
    //cout << "Game dtor" << endl;
    delete pc;
    for (int i = 0; i < 5; i++) {
        delete this->v[i];
    }
}
//consider player enemy movement after every round

















