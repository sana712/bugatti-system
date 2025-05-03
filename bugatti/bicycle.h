#pragma once
#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"
#include "Rentable.h"
#include <iostream>

class Bicycle : public Vehicle, public Rentable {
public:
    Bicycle(std::string manu, std::string mod, std::string col, int yr, int maxSpd, int dailyPrice);

   
    void drive() const override;

    void display() const override;

    
    void rent(int days) override;

   
    void returnItem() override;

};

#endif
