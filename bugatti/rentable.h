#pragma once
#ifndef RENTABLE_H
#define RENTABLE_H

class Rentable {
protected:
    int dailyPrice;
    bool isRented;

public:
    Rentable(int dp) : dailyPrice(dp), isRented(false) {}
    virtual void rent(int days) = 0;
    virtual void returnItem() = 0;
    virtual bool getIsRented() const { return isRented; }
    virtual ~Rentable() {}
};

#endif
