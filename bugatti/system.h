#pragma once

#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include "vehicle.h"


class Car;
class Motorcycle;
class Bicycle;

struct Node {
    Vehicle* item;   
    int id;          
    Node* next;      

    Node(Vehicle* v, int identifier)
        : item(v), id(identifier), next(nullptr) {
    }
};

class System {
private:
    Node* head;      
    int nextId;     

public:
    System();
    ~System();

   
    void addcar(const std::string& manu, const std::string& mod,
        const std::string& col, int year, int maxSpd, int price);
    void addmotorcycle(const std::string& manu, const std::string& mod,
        const std::string& col, int year, int maxSpd,
        int price, int dailyPrice);
    void addbicycle(const std::string& manu, const std::string& mod,
        const std::string& col, int year, int maxSpd,
        int dailyPrice);

    
    void displayAll() const;
    void sellItem(int id);
    void rentItem(int id, int days);
    void returnItem(int id);
    void testItem(int id);

private:
  
    Node* findNode(int id) const;
    void removeNode(Node* prev, Node* toRemove);
};

#endif

