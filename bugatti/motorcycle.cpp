#include "motorcycle.h"
Motorcycle::Motorcycle(std::string manu, std::string mod, std::string col, int yr, int maxSpd, int p, int dailyPrice)
    : Vehicle(manu, mod, col, yr, maxSpd), Sellable(p), Rentable(dailyPrice) {
}

void Motorcycle::drive() const  {
    std::cout << "The motorcycle is driving at a speed of " << maxSpeed / 2 << " km/h (be careful!).\n";
}


void Motorcycle::display() const  {
    std::cout << "Motorcycle Manufacturer: " << manufacturer << "\n"
        << "Model: " << model << "\n"
        << "Color: " << color << "\n"
        << "Year: " << year << "\n"
        << "Max Speed: " << maxSpeed << " km/h\n"
        << "Price: $" << price << "\n"
        << "Daily Rent Price: $" << dailyPrice << "\n";
}


void Motorcycle::sell()  {
    std::cout << "The motorcycle has been sold for $" << price << ".\n";
}

void Motorcycle::rent(int days)  {
    if (isRented) {
        std::cout << "This motorcycle is already rented.\n";
    }
    else {
        isRented = true;
        std::cout << "The motorcycle has been rented for " << days << " days. Total rental cost: $"
            << days * dailyPrice << ".\n";
    }
}


void Motorcycle::returnItem()  {
    if (isRented) {
        isRented = false;
        std::cout << "The motorcycle has been returned. It is now available for rent.\n";
    }
    else {
        std::cout << "This motorcycle is not currently rented.\n";
    }
}