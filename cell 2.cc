//
//  cell.cpp
//  cc3k
//
//  Created by j539li on 2017-07-17.
//  Copyright © 2017 j539li. All rights reserved.
//

#include "cell.h"

using namespace std;

void Cell::setCell(int x, int y, char type) {
    this->x = x;
    this->y = y;
    display = type;
    _content = nullptr;
    __content = nullptr;
    numberofneighbours = 0;
}

Cell::Cell() {
    _content = nullptr;
    __content = nullptr;
}

void Cell::rmobject() {
    _content = nullptr;
    __content = nullptr;
}


void Cell::set_item(Item* addr){
    __content = addr;
    
}

void Cell::set_enemy(Character* addr) {
    _content = addr;
}


int Cell::getx() {
    return x;
}

int Cell::gety() {
    return y;
}

void Cell::setDisplay(char dis){
    this->display=dis;
}

char Cell::getDisplay() const{
    return display;
}

Cell* Cell::getNeighbour(int pos){
    return neighbours[pos];
}

Character* Cell::getCharacter(){
    return _content;
}

Item* Cell::getItem() {
    return __content;
}


Cell::~Cell() {

}
