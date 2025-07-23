#include "Property.h"

// Set the weight of shippable item
Shippable::Shippable(double w) : weight(w) {}

// Set the expiration date of Expirable item
Expirable::Expirable(int year, int month, int day)
    : expirationDate(create_date(year, month, day)) {}

// Check if the item is Expired
bool Expirable::isExpired() const {
    return std::chrono::system_clock::now() > expirationDate;
}