#ifndef CART_H
#define CART_H

#include <map>

class Product;

class Cart {
private:
    std::map<Product*, int> items;
public:
    bool addProduct(Product* product, int quantity);
    const std::map<Product*, int>& getItems() const;
    void setItems(const std::map<Product*, int> &items);
    double calculateSubtotal() const;
    bool isEmpty() const;
};

#endif