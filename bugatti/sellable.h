#pragma once
#ifndef SELLABLE_H
#define SELLABLE_H
#include <iostream>

class Sellable {
protected:
    int price;

public:
    Sellable(int p) : price(p) {}
    virtual void sell() = 0;
    virtual ~Sellable() {}
};

#endif
