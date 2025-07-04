#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include "Property.h"

class Product {
private:
    std::string name;
    double price;
    int quantity;
    std::vector<Property*> properties;

public:
    Product(std::string name, double price, int quantity);
    ~Product();

    std::string getName() const;
    double getPrice() const;
    int getAvailableQuantity() const;
    void setName(const std::string &name);
    void setPrice(double price);
    void setQuantity(int quantity);
    void reduceQuantity(int amount);
    void addProperty(Property* Property);

    // to get the properties of the product
    template<typename T>
    T* getProperty() const {
        for (const auto& property : properties) {
            if (T* target = dynamic_cast<T*>(property))
                return target;
        }
        return nullptr;
    }
};

#endif // PRODUCT_H