//
//  item.cpp
//  item
//
//  Created by 姚博伦 on 2017/7/17.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#include "item.h"

Item::Item(string type): type{type}{}
Item::~Item(){}
string Item::getType() const{
    return type;
}
