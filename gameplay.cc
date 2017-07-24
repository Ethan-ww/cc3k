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
Gameplay::Gameplay(): is_hostile{false}, champion{' '}, pc{nullptr}, curr{0}, file{""}{}

Gameplay::Gameplay(string file): is_hostile{false}, champion{' '}, curr{0}, file{file}{}




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
    if(file==""){
        for (int i = 0; i < 5; i++) {
            this->v[i]= new Floor(pc);
        }
    }else{
        for (int i = 0; i < 5; i++) {
            this->v[i]= new Floor(file,i,pc);
        }
    }
    v[curr]->DisplayMap();
}

int Gameplay::create_game(){
    cout << "Choose a champion:" << endl;
    cout << "s---shade" <<endl;
    cout << "d---drow" <<endl;
    cout << "v---vampire" <<endl;
    cout << "t---troll" <<endl;
    cout << "g---goblin" <<endl;
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
                        ++curr;
                        info = "PC moves to the next floor!";
                        displayall(info);
                        pc->reset();
                        continue;
                        // moves to next floor
                    }
                }
                
                if(mode){
                    v[curr]->move_enemy();
                }
                info += v[curr]->attackplayer(is_hostile); // enemys around attack player
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
                        break;
                    case 'r':
                        return 1;
                    case 'q':
                        return 2;
                    default:
                        break;
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
    pc->trollAddHp();
    v[curr]->DisplayMap();
    cout << "Current floor: " << curr+1 << endl;
    cout << "Race: " << pc->getType() << " Gold: " << pc->getGold() << endl;
    cout << "Hp: " << pc->getHp() <<endl;
    cout << "Atk: " << pc->getAtk() <<endl;
    cout << "Def: " << pc->getDef() <<endl;
    if(info == "PC is dead!" || info == "Game win!"){
        info = info + "\n1-playagain \n2-quit\n";
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

















