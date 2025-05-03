#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "Sellable.h"
#include <iostream>

class Car : public Vehicle, public Sellable {
public:
    Car(std::string manu, std::string mod, std::string col, int yr, int maxSpd, int p);

   
    void drive() const override;

  
    void display() const override;

    // پیاده‌سازی تابع فروش
    void sell() override;
};

#endif
