//
//  floor.cpp
//  cc3k
//
//  Created by j539li on 2017-07-17.
//  Copyright © 2017 j539li. All rights reserved.
//

#include "floor.h"

//vector<vector<Cell>> grid;
//vector<vector<Cell>> chamber;
//vector<cell> availableCell;

using namespace std;

Floor::Floor() {
    //cout << "Default cotr" <<endl;
    ifstream map("floor.txt");
    char ch = 'a';

    for (int i = 0; i < height; i++) {
        vector<Cell> temp;
        for (int j = 0; j < width; j++) {
            map.read(&ch,1);
            Cell a = Cell();
            a.setCell(i,j,ch); // set coordinate and display of cell here
            temp.push_back(a);

        }

        grid.push_back(temp);
    }
    
    
    // set chambers from here
    vector<Cell*> temp1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width;j++) {
            if (i > 2 && i < 7) {
                if (j < 29 && j > 2) {
                    Cell* a = &(grid[i][j]);
                    temp1.push_back(a);
                }
            }
        }
    }
    chamber.push_back(temp1);
    vector<Cell*> temp2;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width;j++) {
            if (i == 3 || i == 4) {
                if (j < 62 && j > 38) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }else if (i == 5) {
                if (j < 70 && j > 38) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }else if (i == 6) {
                if (j < 73 && j > 38) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }else if ( i > 6 && i < 13) {
                if (j > 60 && j < 78) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }
        }
    }
    chamber.push_back(temp2);
    vector<Cell*> temp3;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i < 13 && i > 9) {
                if (j > 37 && j < 50) {
                    Cell* a = &(grid[i][j]);
                    temp3.push_back(a);
                }
            }
        }
    }
    chamber.push_back(temp3);
    vector<Cell*> temp4;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i < 22 && i > 14) {
                if (j > 3 && j < 25) {
                    Cell* a = &(grid[i][j]);
                    temp4.push_back(a);
                }
            }
        }
    }
    chamber.push_back(temp4);
    vector<Cell*> temp5;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 16 || i == 17 || i == 18) {
                if (j > 64 && j < 76) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }else if (i < 22 && i > 18) {
                if (j > 36 && j < 76) {
                    Cell* a = &(grid[i][j]);
                    temp5.push_back(a);
                }
            }
        }
    }
    chamber.push_back(temp5);

    
    // add neighbours to every cells here
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <  width; j++) {
            if (is_valid(i-1, j-1)) {
                grid[i][j].neighbours.push_back(&(grid[i-1][j-1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i, j-1)) {
                grid[i][j].neighbours.push_back(&(grid[i][j-1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i+1, j-1)) {
                grid[i][j].neighbours.push_back(&(grid[i+1][j-1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i-1, j)) {
                grid[i][j].neighbours.push_back(&(grid[i-1][j]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i+1, j)) {
                grid[i][j].neighbours.push_back(&(grid[i+1][j]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i-1, j+1)) {
                grid[i][j].neighbours.push_back(&(grid[i-1][j+1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i, j+1)) {
                grid[i][j].neighbours.push_back(&(grid[i][j+1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i+1, j+1)) {
                grid[i][j].neighbours.push_back(&(grid[i+1][j+1]));
                grid[i][j].numberofneighbours++;
            }
        }
    }

}


Floor::Floor(string filename, int floorindex,Character* pc) {
    ifstream map("cc3kfloor.txt");
    char ch = 'a';
    string willneveruse;
    for (int k = 0; k <= floorindex;k++) {
    for (int i = 0; i < 25; i++) {
        getline(map, willneveruse);
    }
    }
    vector<string> lop = {"RH", "BA", "BD", "PH", "WA", "WD","normal","small","merchant_hoard","dragon_hoard"};
    for (int i = 0; i < height; i++) {
        vector<Cell> temp;
        for (int j = 0; j < width; j++) {
            map.read(&ch,1);
            Cell a = Cell();
            if (ch == '0') {
                a.setCell(i,j,'P');
                Potion* addr = new Potion(lop[0],is_drow); // spawn RH
                listofpotion.push_back(addr);
                a.set_item(addr);
            }else if (ch == '1') {
                a.setCell(i,j,'P');
                Potion* addr = new Potion(lop[1],is_drow); // spawn BA
                listofpotion.push_back(addr);
                a.set_item(addr);
            }else if (ch == '2') {
                a.setCell(i,j,'P');
                Potion* addr = new Potion(lop[2],is_drow); // spawn BD
                listofpotion.push_back(addr);
                a.set_item(addr);
            }else if (ch == '3') {
                a.setCell(i,j,'P');
                Potion* addr = new Potion(lop[3],is_drow); // spawn PH
                listofpotion.push_back(addr);
                a.set_item(addr);
            }else if (ch == '4') {
                a.setCell(i,j,'P');
                Potion* addr = new Potion(lop[4],is_drow); // spawn WA
                listofpotion.push_back(addr);
                a.set_item(addr);
            }else if (ch == '5') {
                a.setCell(i,j,'P');
                Potion* addr = new Potion(lop[5],is_drow); // spawn WD
                listofpotion.push_back(addr);
                a.set_item(addr);
            }else if (ch == '6') {
                a.setCell(i,j,'G');
                Treasure* addr = new Treasure(lop[6],nullptr); // spawn normal gold
                listoftreasure.push_back(addr);
                a.set_item(addr);
            }else if (ch == '7') {
                a.setCell(i,j,'G');
                Treasure* addr = new Treasure(lop[7],nullptr); // spawn small gold
                listoftreasure.push_back(addr);
                a.set_item(addr);
            }else if (ch == '8') {
                a.setCell(i,j,'G');
                Treasure* addr = new Treasure(lop[8],nullptr); // spawn merchant hoard
                listoftreasure.push_back(addr);
                a.set_item(addr);
            }else if (ch == '9') {
                a.setCell(i, j, 'G');
                Treasure* addr = new Treasure(lop[9],nullptr); // spawn dragon hoard
                listoftreasure.push_back(addr);
                a.set_item(addr);
            }else if (ch == '@') { // set player
                a.setCell(i,j,ch);
                a.set_enemy(pc);
                playerX = i;
                playerY = j;
                temp.push_back(a);
            }else if (ch == '\\') { // set stair
                a.setCell(i, j, ch);
                temp.push_back(a);
            }else if (ch == 'H') { // set human
                a.setCell(i, j, '.');
                Human* addr = new Human();
                listofenmey.push_back(addr);
                a.set_enemy(addr);
                temp.push_back(a);
            }else if (ch == 'W') { // set dwarf
                a.setCell(i, j, '.');
                Dwarf* addr = new Dwarf();
                listofenmey.push_back(addr);
                a.set_enemy(addr);
                temp.push_back(a);
            }else if (ch == 'E') { // set elf
                a.setCell(i, j, '.');
                Elf* addr = new Elf();
                listofenmey.push_back(addr);
                a.set_enemy(addr);
                temp.push_back(a);
            }else if (ch == 'O') { // set orc
                a.setCell(i, j, '.');
                Orcs* addr = new Orcs();
                listofenmey.push_back(addr);
                a.set_enemy(addr);
                temp.push_back(a);
            }else if (ch == 'M') { // set merchant
                a.setCell(i, j, '.');
                Merchant* addr = new Merchant();
                listofenmey.push_back(addr);
                a.set_enemy(addr);
                temp.push_back(a);
            }else if (ch == 'D') { // set dragon
                a.setCell(i, j, '.');
                Dragon* addr = new Dragon();
                listofenmey.push_back(addr);
                a.set_enemy(addr);
                temp.push_back(a);
            }else if (ch == 'L') { // set halfing
                a.setCell(i, j, '.');
                Halfling* addr = new Halfling();
                listofenmey.push_back(addr);
                a.set_enemy(addr);
                temp.push_back(a);
            }else { // set others
                a.setCell(i, j, ch);
                temp.push_back(a);
            }
        }
        
        grid.push_back(temp);
    }
    // set neighbour
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <  width; j++) {
            if (is_valid(i-1, j-1)) {
                grid[i][j].neighbours.push_back(&(grid[i-1][j-1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i, j-1)) {
                grid[i][j].neighbours.push_back(&(grid[i][j-1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i+1, j-1)) {
                grid[i][j].neighbours.push_back(&(grid[i+1][j-1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i-1, j)) {
                grid[i][j].neighbours.push_back(&(grid[i-1][j]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i+1, j)) {
                grid[i][j].neighbours.push_back(&(grid[i+1][j]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i-1, j+1)) {
                grid[i][j].neighbours.push_back(&(grid[i-1][j+1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i, j+1)) {
                grid[i][j].neighbours.push_back(&(grid[i][j+1]));
                grid[i][j].numberofneighbours++;
            }if(is_valid(i+1, j+1)) {
                grid[i][j].neighbours.push_back(&(grid[i+1][j+1]));
                grid[i][j].numberofneighbours++;
            }
        }
    }
    // set dragon hoard pointer to dragon
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (!grid[i][j].getItem()->is_Potion()) {
                if (grid[i][j].getItem()->getType() == lop[9]) {
                    for (int k = 0;  k < grid[i][j].neighbours.size(); k++) {
                        if (grid[i][j].neighbours[k]->getCharacter()->getType() == "dragon") {
                            grid[i][j].getItem()->setdragon(grid[i][j].neighbours[k]->getCharacter());
                        }
                    }
                }
            }
        }
    }
}


void Floor::set_isdrown(bool is){
    this->is_drow = is;
}

bool Floor::is_valid(int x, int y) {
    if (x < height && x >=0 && y >= 0 && y < width){
        return true;
    }else{
        return false;
    }
}

Cell* Floor::getCell(int x, int y) {
    return &(grid[x][y]);
}


void Floor::spawn_player(Character* pc) { // spawn both player and stair
    //cout << "spawn player here" << endl;
    int x, stairX;
    unsigned int y, stairY;
    x = rand() % 5;
    y = rand() % chamber[x].size();
    stairX = rand() % 5;
    while (1) {
        if (stairX == x) {
            stairX = rand() % 5;
        }else {
            break;
        }
    }
    chamber[x][y]->set_enemy(pc); // set player here, share ptr with enemy

    // set the coordinate of player
    
    playerX = chamber[x][y]->getx();
    playerY = chamber[x][y]->gety();
    //cout << playerY << endl;
    //cout << playerX << endl;
    stairY = rand() % chamber[stairX].size();
    chamber[stairX][stairY]->setDisplay('\\');
    //DisplayMap();
}


void Floor::spawn_potions() {
    vector<string> lop = {"RH", "BA", "BD", "PH", "WA", "WD" };
    for (int i = 0; i <  10; i++) {
        //cout << "spawn potion here " << i << endl;
        unsigned int indexofpotion, numofchamber, indexofcellinsidechamber;
        indexofpotion = rand() % 6;
        Potion* a = new Potion(lop[indexofpotion],is_drow);
        listofpotion.push_back(a);
        numofchamber = rand() % 5;
        indexofcellinsidechamber = rand() % chamber[numofchamber].size();
        while(chamber[numofchamber][indexofcellinsidechamber]->getItem() != nullptr || // not a item
              chamber[numofchamber][indexofcellinsidechamber]->getCharacter() != nullptr || // not a character
              chamber[numofchamber][indexofcellinsidechamber]->getDisplay()!= '.') { // not a stair
            
            // if the cell is occupied, find another one
            indexofcellinsidechamber = rand() % chamber[numofchamber].size();
        }
        if (chamber[numofchamber][indexofcellinsidechamber]->getDisplay() == '.') { // set item ptr
            chamber[numofchamber][indexofcellinsidechamber]->set_item(a);
        }
    }
}


void Floor::spawn_enemies() {
    for (int i = 0;i < 20;i++) {
        //cout << "spawn enemy here" << i << endl;
        int x = rand() % 18;
        if (x >= 0 && x <= 3) {
            Character* addr = new Human();
            listofenmey.push_back(addr);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            while (grid[posx][posy].getDisplay() != '.' ||
                   grid[posx][posy].getCharacter() != nullptr||
                   grid[posx][posy].getItem()!=nullptr) {
                posx = rand() % height;
                posy = rand() % width;
            }
                grid[posx][posy].set_enemy(addr);
                //grid[posx][posy].display = 'H';
        }else if (x == 4 || x == 5 || x == 6) {
            Character* addr = new Dwarf();
            listofenmey.push_back(addr);
            
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            while (grid[posx][posy].getDisplay() != '.' ||
                   grid[posx][posy].getCharacter() != nullptr||
                   grid[posx][posy].getItem()!=nullptr) {
                posx = rand() % height;
                posy = rand() % width;
            }
                grid[posx][posy].set_enemy(addr);
        }else if (x >= 7 && x <= 11) {
            Character* addr = new Halfling();
            listofenmey.push_back(addr);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            while (grid[posx][posy].getDisplay() != '.' ||
                   grid[posx][posy].getCharacter() != nullptr||
                   grid[posx][posy].getItem()!=nullptr) {
                posx = rand() % height;
                posy = rand() % width;
            }
                grid[posx][posy].set_enemy(addr);

        }else if (x == 12 || x == 13) {
            Character* addr = new Elf();
            listofenmey.push_back(addr);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            while (grid[posx][posy].getDisplay() != '.' ||
                   grid[posx][posy].getCharacter() != nullptr||
                   grid[posx][posy].getItem()!=nullptr) {
                posx = rand() % height;
                posy = rand() % width;
            }
                grid[posx][posy].set_enemy(addr);
        }else if (x == 14 || x == 15) {
            Character* addr = new Orcs();
            listofenmey.push_back(addr);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            while (grid[posx][posy].getDisplay() != '.' ||
                   grid[posx][posy].getCharacter() != nullptr||
                   grid[posx][posy].getItem()!=nullptr) {
                posx = rand() % height;
                posy = rand() % width;
            }
            
                grid[posx][posy].set_enemy(addr);
        }else if (x == 16 || x == 17) {
            Character* addr = new Merchant();
            listofenmey.push_back(addr);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            while (grid[posx][posy].getDisplay() != '.' ||
                   grid[posx][posy].getCharacter() != nullptr||
                   grid[posx][posy].getItem()!=nullptr) {
                posx = rand() % height;
                posy = rand() % width;
            }
                grid[posx][posy].set_enemy(addr);
        }
    }
}

void Floor::spawn_gold() {
    for (int i = 0; i < 10; i++) {
        //cout << "spawn gold here" << i << endl;
        int x = rand() % 8;
        if (x >= 0 && x <= 4) {
            Treasure* a = new Treasure("normal",nullptr);
            listoftreasure.push_back(a);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            while (grid[posx][posy].getDisplay() != '.' ||
                   grid[posx][posy].getCharacter() != nullptr||
                   grid[posx][posy].getItem()!=nullptr) {
                posx = rand() % height;
                posy = rand() % width;
            }
            if (grid[posx][posy].getDisplay() == '.') {
                grid[posx][posy].set_item(a);
            }
        }else if (x == 5) {
            Character* d = new Dragon();
            listofenmey.push_back(d);
            Treasure* a = new Treasure("dragon_hoard",d);
            listoftreasure.push_back(a);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            while (grid[posx][posy].getDisplay() != '.' ||
                   grid[posx][posy].getCharacter() != nullptr||
                   grid[posx][posy].getItem()!=nullptr) {
                posx = rand() % height;
                posy = rand() % width;
            }
            grid[posx][posy].set_item(a);
            unsigned int dpos = rand() % grid[posx][posy].numberofneighbours;
            while (grid[posx][posy].getNeighbour(dpos)->getDisplay() != '.'|| // find a free neighbour cell
                   grid[posx][posy].getNeighbour(dpos)->getCharacter()!=nullptr||
                   grid[posx][posy].getNeighbour(dpos)->getItem()!=nullptr)
            {
                dpos =rand() % grid[posx][posy].numberofneighbours;
            }
            grid[posx][posy].getNeighbour(dpos)->set_enemy(d); // set dragon
            
        }else if (x == 6 || x == 7) {
            Treasure* a = new Treasure("small",nullptr);
            listoftreasure.push_back(a);
            int posx,posy;
            posx = rand() % height;
            posy = rand() % width;
            while (grid[posx][posy].getDisplay() != '.' ||
                   grid[posx][posy].getCharacter() != nullptr||
                   grid[posx][posy].getItem()!=nullptr) {
                posx = rand() % height;
                posy = rand() % width;
            }
            grid[posx][posy].set_item(a);
        }
        
    }
}

void Floor::move_enemy() {
    vector<Character*> temp;
    for (int i = 0;i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(grid[i][j].getCharacter()!=nullptr){
                if (grid[i][j].getCharacter()->isEnemy() && grid[i][j].getCharacter()->getType()!="dragon") {
                    bool is_moved = false;
                    for (unsigned int k = 0; k < temp.size(); k++) {
                        if (grid[i][j].getCharacter() == temp[i]) {
                            is_moved = true;
                        }
                    }
                    if (!is_moved) {
                        unsigned int pos = rand() % grid[i][j].neighbours.size();
                        while (grid[i][j].neighbours[pos]->getDisplay() != '.'||
                               grid[i][j].neighbours[pos]->getCharacter()!= nullptr ||
                               grid[i][j].neighbours[pos]->getItem()!= nullptr) {
                            pos = rand() % grid[i][j].neighbours.size();
                        }
                        Character *ec=grid[i][j].getCharacter();
                        temp.push_back(ec);
                        grid[i][j].neighbours[pos]->set_enemy(ec);
                        grid[i][j].set_enemy(nullptr);
                        
                    }
                }
            }
        }

    }
    cout << "enemy moved" << endl;
}


void Floor::swap(Cell* newcell, Cell* oldcell) { //swap character pointer
    Character* ptr = oldcell->getCharacter();
    oldcell->set_enemy(newcell->getCharacter());
    newcell->set_enemy(ptr);
}



string Floor::move_player(string dir){
    if (dir == "no") {
        if (grid[playerX-1][playerY].getCharacter() == nullptr &&
            grid[playerX-1][playerY].getItem() == nullptr) {
            if (grid[playerX-1][playerY].getDisplay() == '.' ||
                grid[playerX-1][playerY].getDisplay() == '#' ||
                grid[playerX-1][playerY].getDisplay() == '+') {
                swap(&grid[playerX-1][playerY],&grid[playerX][playerY]);
                playerX--;
                return "PC move north.";
            }
            if (grid[playerX-1][playerY].getDisplay() == '\\') {
                return "true";
            }
        }else if (grid[playerX-1][playerY].getCharacter() == nullptr) {
            if (!grid[playerX-1][playerY].getItem()->is_Potion()) {
                if (grid[playerX-1][playerY].getItem()->getdragon() == nullptr) {
                    grid[playerX-1][playerY].getItem()->effect(grid[playerX][playerY].getCharacter());
                    grid[playerX-1][playerY].set_item(nullptr);
                    swap(&grid[playerX-1][playerY],&grid[playerX][playerY]);
                    playerX--;
                    return "PC move north.";
                }else{
                    swap(&grid[playerX-1][playerY],&grid[playerX][playerY]);
                    playerX--;
                    return "PC move north.";
                }
            }
        }
    }else if (dir == "so") {
        if (grid[playerX+1][playerY].getCharacter() == nullptr &&
            grid[playerX+1][playerY].getItem() == nullptr) {
            if (grid[playerX+1][playerY].getDisplay() == '.' ||
                grid[playerX+1][playerY].getDisplay() == '#' ||
                grid[playerX+1][playerY].getDisplay() == '+') {
                swap(&grid[playerX+1][playerY],&grid[playerX][playerY]);
                playerX++;
                return "PC move south.";
            }
            if (grid[playerX+1][playerY].getDisplay() == '\\') {
                return "true";
            }
        }else if (grid[playerX+1][playerY].getCharacter() == nullptr) {
            if (!grid[playerX+1][playerY].getItem()->is_Potion()) {
                if (grid[playerX+1][playerY].getItem()->getdragon() == nullptr) {
                    grid[playerX+1][playerY].getItem()->effect(grid[playerX][playerY].getCharacter());
                    grid[playerX+1][playerY].set_item(nullptr);
                    swap(&grid[playerX+1][playerY],&grid[playerX][playerY]);
                    playerX++;
                    return "PC move south.";
                }else{
                    swap(&grid[playerX+1][playerY],&grid[playerX][playerY]);
                    playerX++;
                    return "PC move south.";
                }
            }
        }

    }else if (dir == "ea"){
        if (grid[playerX][playerY+1].getCharacter() == nullptr &&
            grid[playerX][playerY+1].getItem() == nullptr) {
            if (grid[playerX][playerY+1].getDisplay() == '.' ||
                grid[playerX][playerY+1].getDisplay() == '#' ||
                grid[playerX][playerY+1].getDisplay() == '+') {
                swap(&grid[playerX][playerY+1],&grid[playerX][playerY]);
                playerY++;
                return "PC move east.";
            }
            if (grid[playerX][playerY+1].getDisplay() == '\\') {
                return "true";
            }
        }else if (grid[playerX][playerY+1].getCharacter() == nullptr) {
            if (!grid[playerX][playerY+1].getItem()->is_Potion()) {
                if (grid[playerX][playerY+1].getItem()->getdragon() == nullptr) {
                    grid[playerX][playerY+1].getItem()->effect(grid[playerX][playerY].getCharacter());
                    grid[playerX][playerY+1].set_item(nullptr);
                    swap(&grid[playerX][playerY+1],&grid[playerX][playerY]);
                    playerY++;
                    return "PC move east.";
                }else{
                    swap(&grid[playerX][playerY+1],&grid[playerX][playerY]);
                    playerY++;
                    return "PC move east.";
                }
            }
        }
        
    }else if (dir == "we") {
        if (grid[playerX][playerY-1].getCharacter() == nullptr &&
            grid[playerX][playerY-1].getItem() == nullptr) {
            if (grid[playerX][playerY-1].getDisplay() == '.' ||
                grid[playerX][playerY-1].getDisplay() == '#' ||
                grid[playerX][playerY-1].getDisplay() == '+') {
                swap(&grid[playerX][playerY-1],&grid[playerX][playerY]);
                playerY--;
                return "PC move west.";
            }
            if (grid[playerX][playerY-1].getDisplay() == '\\') {
                return "true";
            }
        }else if (grid[playerX][playerY-1].getCharacter() == nullptr) {
            if (!grid[playerX][playerY-1].getItem()->is_Potion()) {
                if (grid[playerX][playerY-1].getItem()->getdragon() == nullptr) {
                    grid[playerX][playerY-1].getItem()->effect(grid[playerX][playerY].getCharacter());
                    grid[playerX][playerY-1].set_item(nullptr);
                    swap(&grid[playerX][playerY-1],&grid[playerX][playerY]);
                    playerY--;
                    return "PC move west.";
                }else{
                    swap(&grid[playerX][playerY-1],&grid[playerX][playerY]);
                    playerY--;
                    return "PC move west.";
                }
            }
        }
    }else if (dir == "ne") {
        if (grid[playerX-1][playerY+1].getCharacter() == nullptr &&
            grid[playerX-1][playerY+1].getItem() == nullptr) {
            if (grid[playerX-1][playerY+1].getDisplay() == '.' ||
                grid[playerX-1][playerY+1].getDisplay() == '#' ||
                grid[playerX-1][playerY+1].getDisplay() == '+') {
                swap(&grid[playerX-1][playerY+1],&grid[playerX][playerY]);
                playerY++;
                playerX--;
                return "PC move northeast.";
            }
            if (grid[playerX-1][playerY+1].getDisplay() == '\\') {
                return "true";
            }
        }else if (grid[playerX-1][playerY+1].getCharacter() == nullptr) {
            if (!grid[playerX-1][playerY+1].getItem()->is_Potion()) {
                if (grid[playerX-1][playerY+1].getItem()->getdragon() == nullptr) {
                    grid[playerX-1][playerY+1].getItem()->effect(grid[playerX][playerY].getCharacter());
                    grid[playerX-1][playerY+1].set_item(nullptr);
                    swap(&grid[playerX-1][playerY+1],&grid[playerX][playerY]);
                    playerY++;
                    playerX--;
                    return "PC move northeast.";
                }else{
                    swap(&grid[playerX-1][playerY+1],&grid[playerX][playerY]);
                    playerY++;
                    playerX--;
                    return "PC move northeast.";
                }
            }
        }
    }else if (dir == "nw") {
        if (grid[playerX-1][playerY-1].getCharacter() == nullptr &&
            grid[playerX-1][playerY-1].getItem() == nullptr) {
            if (grid[playerX-1][playerY-1].getDisplay() == '.' ||
                grid[playerX-1][playerY-1].getDisplay() == '#' ||
                grid[playerX-1][playerY-1].getDisplay() == '+') {
                swap(&grid[playerX-1][playerY-1],&grid[playerX][playerY]);
                playerY--;
                playerX--;
                return "PC move northwest.";
            }
            if (grid[playerX-1][playerY-1].getDisplay() == '\\') {
                return "true";
            }
        }else if (grid[playerX-1][playerY-1].getCharacter() == nullptr) {
            if (!grid[playerX-1][playerY-1].getItem()->is_Potion()) {
                if (grid[playerX-1][playerY-1].getItem()->getdragon() == nullptr) {
                    grid[playerX-1][playerY-1].getItem()->effect(grid[playerX][playerY].getCharacter());
                    grid[playerX-1][playerY-1].set_item(nullptr);
                    swap(&grid[playerX-1][playerY-1],&grid[playerX][playerY]);
                    playerY--;
                    playerX--;
                    return "PC move northwest.";
                }else{
                    swap(&grid[playerX-1][playerY-1],&grid[playerX][playerY]);
                    playerY--;
                    playerX--;
                    return "PC move northwest.";
                }
            }
        }
    }else if (dir == "se") {
        if (grid[playerX+1][playerY+1].getCharacter() == nullptr &&
            grid[playerX+1][playerY+1].getItem() == nullptr) {
            if (grid[playerX+1][playerY+1].getDisplay() == '.' ||
                grid[playerX+1][playerY+1].getDisplay() == '#' ||
                grid[playerX+1][playerY+1].getDisplay() == '+') {
                swap(&grid[playerX+1][playerY+1],&grid[playerX][playerY]);
                playerY++;
                playerX++;
                return "PC move southeast.";
            }
            if (grid[playerX+1][playerY+1].getDisplay() == '\\') {
                return "true";
            }
        }else if (grid[playerX+1][playerY+1].getCharacter() == nullptr) {
            if (!grid[playerX+1][playerY+1].getItem()->is_Potion()) {
                if (grid[playerX+1][playerY+1].getItem()->getdragon() == nullptr) {
                    grid[playerX+1][playerY+1].getItem()->effect(grid[playerX][playerY].getCharacter());
                    grid[playerX+1][playerY+1].set_item(nullptr);
                    swap(&grid[playerX-1][playerY+1],&grid[playerX][playerY]);
                    playerY++;
                    playerX++;
                    return "PC move southeast.";
                }else{
                    swap(&grid[playerX+1][playerY+1],&grid[playerX][playerY]);
                    playerY++;
                    playerX++;
                    return "PC move southeast.";
                }
            }
        }
    }else if (dir == "sw") {
        if (grid[playerX+1][playerY-1].getCharacter() == nullptr &&
            grid[playerX+1][playerY-1].getItem() == nullptr) {
            if (grid[playerX+1][playerY-1].getDisplay() == '.' ||
                grid[playerX+1][playerY-1].getDisplay() == '#' ||
                grid[playerX+1][playerY-1].getDisplay() == '+') {
                swap(&grid[playerX+1][playerY-1],&grid[playerX][playerY]);
                playerY--;
                playerX++;
                return "PC move southwest.";
            }
            if (grid[playerX+1][playerY-1].getDisplay() == '\\') {
                return "true";
            }
        }else if (grid[playerX+1][playerY-1].getCharacter() == nullptr) {
            if (!grid[playerX+1][playerY-1].getItem()->is_Potion()) {
                if (grid[playerX+1][playerY-1].getItem()->getdragon() == nullptr) {
                    grid[playerX+1][playerY-1].getItem()->effect(grid[playerX][playerY].getCharacter());
                    grid[playerX+1][playerY-1].set_item(nullptr);
                    swap(&grid[playerX-1][playerY-1],&grid[playerX][playerY]);
                    playerY--;
                    playerX++;
                    return "PC move southwest.";
                }else{
                    swap(&grid[playerX+1][playerY-1],&grid[playerX][playerY]);
                    playerY--;
                    playerX++;
                    return "PC move southwest.";
                }
            }
        }

    }
    return "false";
}



void Floor::DisplayMap() {
    for(int i = 0; i < height; i ++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j].getCharacter() != nullptr && grid[i][j].getItem()!=nullptr) {
                cout << '@';
            }else if (grid[i][j].getCharacter() != nullptr && !grid[i][j].getCharacter()->isEnemy()) { // has a character and is not enemy
                cout << '@';
            }else if (grid[i][j].getCharacter() != nullptr && grid[i][j].getCharacter()->isEnemy()) { // has a character and is enemy
                string s = grid[i][j].getCharacter()->getType();
                if(s=="human"){
                    cout << 'H';
                }else if(s=="dwarf"){
                    cout << 'W';
                }else if(s=="elf"){
                    cout << 'E';
                }else if(s=="orc"){
                    cout << 'O';
                }else if(s=="merchant"){
                    cout << 'M';
                }else if(s=="dragon"){
                    cout << 'D';
                }else if(s=="halfling"){
                    cout << 'L';
                }
            }else if(grid[i][j].getItem()!=nullptr){ // has a item
                if(grid[i][j].getItem()->is_Potion()){
                    cout << 'P';
                }else{
                    cout << 'G';
                }
            }else {
                cout << grid[i][j].getDisplay();
            }
        }
    }
}

Floor::~Floor() {
    cout << "dtor" << endl;
    unsigned int x;
    x = listofenmey.size();
    for (int i = 0; i < x; i++) {
        delete listofenmey[i];
    }
    x = listoftreasure.size();
    for (int i = 0;i < x; i++) {
        delete listoftreasure[i];
    }
    x = listofpotion.size();
    for (int i = 0; i < x; i++) {
        delete listofpotion[i];
    }
}

Cell* Floor::newcord(string dir, int x, int y){
    Cell *c;
    if (dir == "no"){
        c = getCell(x - 1, y);
    } else if (dir == "so") {
        c= getCell(x + 1, y);
    } else if (dir == "ea") {
        c= getCell(x, y + 1);
    } else if (dir == "we") {
        c= getCell(x, y - 1);
    } else if (dir == "ne") {
        c= getCell(x - 1, y + 1);
    } else if (dir == "nw") {
        c= getCell(x - 1, y - 1);
    } else if(dir == "se") {
        c= getCell(x + 1, y + 1);
    } else if (dir == "sw"){
        c= getCell(x + 1, y - 1);
    }
    return c;
}


string Floor::usepotion(string dir){
    Cell *n = newcord(dir, playerX, playerY);
    Item *p;
    Character *player;
    string info="Posion info";
    if(n->getItem()!=nullptr){
        if(n->getItem()->is_Potion()) {
            p = n->getItem();
            player = grid[playerX][playerY].getCharacter();
            info=p->effect(player);
        } else {
            throw "That is not a potion";
        }
    }
    n->set_item(nullptr);
    if(player->getHp() == 0){//player die by using poison
        return "PC is dead!";
    }
    return "PC uses " + info;
}

string Floor::attackenemy(string dir, bool& is_hostile){
    Cell *c = newcord(dir, playerX, playerY);
    Character *nc;
    Character *player=grid[playerX][playerY].getCharacter();
    string info;
    if(c->getCharacter()!=nullptr){
        nc=c->getCharacter();
    }else{
        return "No player there!"; // no enemy? stop here
    }
    
    if(nc->getType() == "merchant"){
        is_hostile = true; // set all merchant as hostile
        info = player->attack(nc);
    } else {
        info = player->attack(nc);
    }
    if(nc->getHp() == 0){//enemy die
        c->set_enemy(nullptr); // remove enemy ptr
        if(nc->getType() == "human"){
            Treasure* t= new Treasure("human_normal", nullptr);
            listoftreasure.push_back(t);
            c->set_item(t);
        } else if(nc->getType() == "dragon"){
            int len = c->numberofneighbours;
            for(int i = 0; i < len; ++i){
                if(c->getNeighbour(i)->getItem()!=nullptr){ // set dragon hoard to be pickable
                    Item *item = c->getNeighbour(i)->getItem();
                    if(!(item->is_Potion())){
                        item->setdragon(nullptr);
                    }
                }
            }
        } else if(nc->getType() == "merchant"){
            Treasure* m=new Treasure("merchant_hoard", nullptr);
            listoftreasure.push_back(m);
            c->set_item(m);
        } else{
            player->addGold(nc->getGold());
        }
    }
    return info;
}

string Floor::attackplayer(bool is_hostile){
    string info="";
    Cell *playerCell = &grid[playerX][playerY];
    Character *pc = playerCell->getCharacter();
    int len = playerCell->numberofneighbours;
    for (int i = 0; i < len; i++){
        if(playerCell->getNeighbour(i)->getCharacter()!=nullptr){ // find the enemies
                Character *nc = playerCell->getNeighbour(i)->getCharacter();
                if(nc->getType() == "elf"){
                    if(pc->getType() != "drow"){
                        info = nc->attack(pc);
                        info += nc->attack(pc);
                    }else{
                        info=nc->attack(pc);
                    }
                } else if (nc->getType() == "merchant"){ // enemy is a merchant
                    if(is_hostile){
                        info = nc->attack(pc);
                    }
                } else{
                    info = nc->attack(pc);
                }
        }else if(playerCell->getNeighbour(i)->getItem()!=nullptr){
            Item *item = playerCell->getNeighbour(i)->getItem();
            if((!item->is_Potion())){
                if((item->getdragon()!=nullptr)) info+=item->getdragon()->attack(pc);
            }
    }
        if(pc->getHp() == 0){
            return "PC is dead!";
        } else {
            return info;
        }
    }
    return info;
}

 
