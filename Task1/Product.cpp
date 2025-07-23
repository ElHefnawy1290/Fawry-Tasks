#include "Product.h"

Product::Product(std::string name, double price, int quantity)
    : name(std::move(name)), price(price), quantity(quantity) {}

// freed up the memory from properties pointers
Product::~Product() {
    for (Property* prop : properties)
        delete prop;
}

std::string Product::getName() const {
  return name;
}

double Product::getPrice() const {
  return price;
}

int Product::getAvailableQuantity() const {
  return quantity;
}

void Product::setName(const std::string &name) {
    this -> name = name;
}

void Product::setPrice(double price) {
    this -> price = price;
}

void Product::setQuantity(int quantity) {
    this -> quantity = quantity;
}

void Product::reduceQuantity(int amount) {
    if (amount > 0 && amount <= quantity)
        quantity -= amount;
}

void Product::addProperty(Property* property) {
    properties.push_back(std::move(property));
}