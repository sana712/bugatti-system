#include "car.h"
Car::Car(std::string manu, std::string mod, std::string col, int yr, int maxSpd, int p)
    : Vehicle(manu, mod, col, yr, maxSpd), Sellable(p) {
}


void Car::drive() const  {
    std::cout << "The car is driving at a speed of " << maxSpeed << " km/h.\n";
}


void Car::display() const  {
    std::cout << "Car Manufacturer: " << manufacturer << "\n"
        << "Model: " << model << "\n"
        << "Color: " << color << "\n"
        << "Year: " << year << "\n"
        << "Max Speed: " << maxSpeed << " km/h\n"
        << "Price: $" << price << "\n";
}

// پیاده‌سازی تابع فروش
void Car::sell()  {
    std::cout << "The car has been sold for $" << price << ".\n";
}