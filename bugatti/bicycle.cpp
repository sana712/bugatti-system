#include "bicycle.h"

Bicycle::Bicycle(std::string manu, std::string mod, std::string col, int yr, int maxSpd, int dailyPrice)
    : Vehicle(manu, mod, col, yr, maxSpd), Rentable(dailyPrice) {
}


void Bicycle::drive() const  {
    std::cout << "The bicycle is pedaling at a speed of " << maxSpeed << " km/h.\n";
}

void Bicycle::display() const  {
    std::cout << "Bicycle Manufacturer: " << manufacturer << "\n"
        << "Model: " << model << "\n"
        << "Color: " << color << "\n"
        << "Year: " << year << "\n"
        << "Max Speed: " << maxSpeed << " km/h\n"
        << "Daily Rent Price: $" << dailyPrice << "\n";
}


void Bicycle::rent(int days)  {
    if (isRented) {
        std::cout << "This bicycle is already rented.\n";
    }
    else {
        isRented = true;
        std::cout << "The bicycle has been rented for " << days << " days. Total rental cost: $"
            << days * dailyPrice << ".\n";
    }
}


void Bicycle::returnItem()  {
    if (isRented) {
        isRented = false;
        std::cout << "The bicycle has been returned. It is now available for rent.\n";
    }
    else {
        std::cout << "This bicycle is not currently rented.\n";
    }
}