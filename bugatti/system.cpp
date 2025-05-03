#include "system.h"
#include "car.h"
#include "motorcycle.h"
#include "bicycle.h"

System::System()
    : head(nullptr), nextId(1) {
}

System::~System() {
    Node* curr = head;
    while (curr) {
        Node* tmp = curr->next;
        delete curr->item;
        delete curr;
        curr = tmp;
    }
}



Node* System::findNode(int id) const {
    Node* curr = head;
    while (curr) {
        if (curr->id == id) return curr;
        curr = curr->next;
    }
    return nullptr;
}



void System::removeNode(Node* prev, Node* toRemove) {
    if (!toRemove) return;
    if (prev) prev->next = toRemove->next;
    else head = toRemove->next;
    delete toRemove->item;
    delete toRemove;
}



void System::addcar(const std::string& manu, const std::string& mod,
    const std::string& col, int year, int maxSpd, int price) {
    Car* car = new Car(manu, mod, col, year, maxSpd, price);
    Node* node = new Node(car, nextId++);
    node->next = head;
    head = node;
}



void System::addmotorcycle(const std::string& manu, const std::string& mod,
    const std::string& col, int year, int maxSpd,
    int price, int dailyPrice) {
    Motorcycle* m = new Motorcycle(manu, mod, col, year, maxSpd, price, dailyPrice);
    Node* node = new Node(m, nextId++);
    node->next = head;
    head = node;
}



void System::addbicycle(const std::string& manu, const std::string& mod,
    const std::string& col, int year, int maxSpd,
    int dailyPrice) {
    Bicycle* b = new Bicycle(manu, mod, col, year, maxSpd, dailyPrice);
    Node* node = new Node(b, nextId++);
    node->next = head;
    head = node;
}



void System::displayAll() const {
    Node* curr = head;
    while (curr) {
        std::cout << "Item ID: " << curr->id << std::endl;
        curr->item->display();
        std::cout << "-----------------------------\n";
        curr = curr->next;
    }
}



void System::sellItem(int id) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        if (curr->id == id) {
            // Dynamic cast to Sellable
            if (auto s = dynamic_cast<Sellable*>(curr->item)) {
                s->sell();
                removeNode(prev, curr);
            }
            else {
                std::cout << "Item " << id << " cannot be sold.\n";
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    std::cout << "Item " << id << " not found.\n";
}



void System::rentItem(int id, int days) {
    Node* node = findNode(id);
    if (!node) {
        std::cout << "Item " << id << " not found.\n";
        return;
    }
    if (auto r = dynamic_cast<Rentable*>(node->item)) {
        r->rent(days);
    }
    else {
        std::cout << "Item " << id << " cannot be rented.\n";
    }
}



void System::returnItem(int id) {
    Node* node = findNode(id);
    if (!node) {
        std::cout << "Item " << id << " not found.\n";
        return;
    }
    if (auto r = dynamic_cast<Rentable*>(node->item)) {
        r->returnItem();
    }
    else {
        std::cout << "Item " << id << " is not rentable.\n";
    }
}

void System::testItem(int id) {
    Node* node = findNode(id);
    if (!node) {
        std::cout << "Item " << id << " not found.\n";
        return;
    }
    node->item->drive();
}
