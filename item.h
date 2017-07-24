//
//  item.hpp
//  item
//
//  Created by 姚博伦 on 2017/7/17.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#ifndef item_h
#define item_h

#include <iostream>
#include <string>
#include "character.h"
using namespace std;

class Item {
protected:
    string type;
public:
    Item(string type);
    virtual bool is_Potion() = 0;
    virtual Character *getdragon(){
        return nullptr;
    }
    string getType() const;
    virtual void setdragon(Character *d) {};
    virtual string effect(Character *c) = 0;
    virtual ~Item();
};





#endif /* item_hpp */
