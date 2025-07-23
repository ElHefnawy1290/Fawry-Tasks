#include "Cart.h"
#include "Product.h"
#include <iostream>

bool Cart::addProduct(Product* product, int quantity) {
    // check for valid product and quantity
    if (!product || quantity <= 0) {
        std::cout << "Error: Invalid product or quantity.\n";
        return false;
    }
    // check that the quantity is enough
    if (quantity > product->getAvailableQuantity()) {
        std::cout << "Error: Not enough " << product->getName() << " in stock.\n";
        return false;
    }
    items[product] += quantity;
    return true;
}

const std::map<Product*, int>& Cart::getItems() const {
    return items;
}

void Cart::setItems(const std::map<Product*, int> &items) {
    this -> items = items;
}

// for calculating total cost of cart
double Cart::calculateSubtotal() const {
    double subtotal{};
    for (const auto& item : items)
        subtotal += item.first->getPrice() * item.second;
    return subtotal;
}

bool Cart::isEmpty() const {
  return items.empty();
}