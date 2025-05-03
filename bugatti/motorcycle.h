#pragma once
#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"
#include "Sellable.h"
#include "Rentable.h"
#include <iostream>

class Motorcycle : public Vehicle, public Sellable, public Rentable {
public:
    Motorcycle(std::string manu, std::string mod, std::string col, int yr, int maxSpd, int p, int dailyPrice);

    void drive() const override;

  
    void display() const override;

   
    void sell() override;

   
    void rent(int days) override;

 
    void returnItem() override;
};

#endif
