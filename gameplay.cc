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
#include "conio.h"
using namespace std;
Gameplay::Gameplay(): is_hostile{false}, champion{' '}, pc{nullptr}, curr{0}, file{""}{
    //system("stty raw");
}

Gameplay::Gameplay(string file): is_hostile{false}, champion{' '}, curr{0}, file{file}{
    //system("stty raw");
}




void Gameplay::setplayer(){
    switch(champion){
        case 's':{
            pc=new Shade();
            break;
        }
        case 'd':{
            pc=new Drow();
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
            v[i]= new Floor(pc);
        }
    }else{
        for (int i = 0; i < 5; i++) {
            v[i]= new Floor(file,i,pc);
        }
    }
    if(champion=='d'){
        v[curr]->set_isdrow(true);
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
        champion=my_getch();
        cout << endl;
        try{
            setplayer();
        } catch(string s){
            cout << s << endl;
        }
        break;

    }

    
    string s="";
    char cmd;
    bool mode = true; // true means normal mode, flase otherwise
    int i = 0;
    while(true){
        string info = "";
        
        cmd=my_getch();
        cout << endl;
            if(cmd == 'w' || cmd == 'a' || cmd == 's' || cmd == 'd'){ // w: no/s: so/a: we/d: ea
                // move player
                switch(cmd){
                    case 'w':{
                        info=v[curr]->move_player("no");
                        break;
                    }
                    case 'a':{
                        info=v[curr]->move_player("we");
                        break;

                    }
                    case 's':{
                        info=v[curr]->move_player("so");
                        break;

                    }
                    case 'd':{
                        info=v[curr]->move_player("ea");
                        break;
                    }
                    default:
                        break;
                }
                if( info == "true"){ // already move here
                    if(curr == 4){
                        displayall("Game win!");
                        i=my_getch();
                        cout << endl;
                        if(i==1){
                            return 1;
                        }else{
                            return 2;
                        }
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
                    i=my_getch();
                    cout << endl;
                    if(i==1){
                        return 1;
                    }else{
                        return 2;
                    }
                }
                displayall(info);
                
            } else{
                switch (cmd) {
                    case 'j': // use potion
                        cmd=my_getch();
                        cout << endl;
                        switch(cmd){
                            case 'w':{
                                info = v[curr]->usepotion("no");
                                break;
                            }
                            case 'a':{
                                info = v[curr]->usepotion("we");
                                break;
                                
                            }
                            case 's':{
                                info = v[curr]->usepotion("so");
                                break;
                                
                            }
                            case 'd':{
                                info = v[curr]->usepotion("ea");
                                break;
                            }
                            default:
                                break;
                        }


                        // info store the information of using potion
                        if(pc->getHp()==0){
                            displayall("PC is dead!");
                            i=my_getch();
                            cout << endl;
                            if(i==1){
                                return 1;
                            }else{
                                return 2;
                            }
                        }
                    
                        if(mode){
                            v[curr]->move_enemy();
                        }
                        info += " ";
                        info += v[curr]->attackplayer(is_hostile); // enemys around attack player
                        if(pc->getHp()==0){
                            displayall("PC is dead!");
                            i=my_getch();
                            cout << endl;
                            if(i==1){
                                return 1;
                            }else{
                                return 2;
                            }
                        }
                        displayall(info);
                        break;
                    case 'k':
                        cmd=my_getch();
                        cout << endl;
                        switch(cmd){
                            case 'w':{
                                info = v[curr]->attackenemy("no",is_hostile);
                                break;
                            }
                            case 'a':{
                                info = v[curr]->attackenemy("we",is_hostile);
                                break;
                                
                            }
                            case 's':{
                                info = v[curr]->attackenemy("so",is_hostile);
                                break;
                                
                            }
                            case 'd':{
                                info = v[curr]->attackenemy("ea",is_hostile);
                                break;
                            }
                            default:
                                break;
                        }
                        //info = v[curr]->attackenemy(cmd,is_hostile);
                        info += v[curr]->attackplayer(is_hostile);
                        if(pc->getHp()==0){
                            displayall("PC is dead!");
                            i=my_getch();
                            cout << endl;
                            if(i==1){
                                return 1;
                            }else{
                                return 2;
                            }
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
    }
}

void Gameplay::displayall(string info){
    if(pc->getHp()!=0) pc->trollAddHp();
    v[curr]->DisplayMap();
    cout << "Current floor: " << curr+1 << endl;
    cout << "Race: " << pc->getType() << " Gold: " << pc->getGold() << endl;
    cout << "Hp: " << pc->getHp() <<endl;
    cout << "Atk: " << pc->getAtk() <<endl;
    cout << "Def: " << pc->getDef() <<endl;
    cout << "Action: " << info<< endl;
    if(info == "PC is dead!" || info == "Game win!"){
        int score=0;
        if(champion=='s'){
            score=pc->getGold()*1.5;
        }else{
            score=pc->getGold();
        }
        cout << "Your final socre: " << score << endl;
        cout << "Enter your choice" << endl;
        cout << "1---Play again" << endl;
        cout << "2---Quit" << endl;
    }
}

Gameplay::~Gameplay(){
    delete pc;
    pc=nullptr;
    for (int i = 0; i < 5; i++) {
        delete this->v[i];
        this->v[i]=nullptr;
    }
}
//consider player enemy movement after every round

















