//
//  main.cpp
//  cc3k
//
//  Created by j539li on 2017-07-18.
//  Copyright © 2017 j539li. All rights reserved.
//

#include <iostream>

#include "gameplay.h"
#include "floor.h"

int main(int argc, const char * argv[]) {
    if(argc==1){
        while(true){
            Gameplay game;
            int i = game.create_game();
            if(i == 1){
                continue;
            } else if(i == 2){
                return 0;
            }
        }

    }else if(argc==2){
        string str=argv[1];
        while(true){
            Gameplay game(str);
            int i = game.create_game();
            if(i == 1){
                continue;
            } else if(i == 2){
                return 0;
            }
        }
    }else{
        std::cerr << "Invalid number of arguments!" <<endl;
    }
}

//    Character* pc = new Vampire();
//    Floor a(pc);
//    a.DisplayMap();
//}
