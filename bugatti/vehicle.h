#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string manufacturer;
    std::string model;
    std::string color;
    int year;
    int maxSpeed;

public:
    Vehicle(std::string manu, std::string mod, std::string col, int yr, int maxSpd)
        : manufacturer(manu), model(mod), color(col), year(yr), maxSpeed(maxSpd) {
    }

    virtual void drive() const = 0;        // تابع انتزاعی
    virtual void display() const = 0;      
    virtual ~Vehicle() {}
};

#endif
