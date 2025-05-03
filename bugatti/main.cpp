#include "System.h"

int main() {
    System store;

    // اضافه کردن آیتم‌ها
    store.addcar("BMW", "M3 GTR", "White & Blue", 2005, 330, 75000);
    store.addmotorcycle("Yamaha", "MT-07", "Matte Black", 2021, 200, 9000, 150);
    store.addbicycle("Giant", "Escape 3", "Red", 2020, 30, 20);

    std::cout << "\n=== All Items ===\n";
    store.displayAll();

    std::cout << "\n=== Test Driving Item 2 ===\n";
    store.testItem(2);

    std::cout << "\n=== Renting Item 3 for 5 days ===\n";
    store.rentItem(3, 5);

    std::cout << "\n=== Trying to Rent Item 3 again ===\n";
    store.rentItem(3, 2);

    std::cout << "\n=== Returning Item 3 ===\n";
    store.returnItem(3);

    std::cout << "\n=== Selling Item 1 ===\n";
    store.sellItem(1);

    std::cout << "\n=== Final Item List ===\n";
    store.displayAll();

    return 0;
}
