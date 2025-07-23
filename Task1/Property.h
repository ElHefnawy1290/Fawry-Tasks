#ifndef PROPERTY_H
#define PROPERTY_H

#include <chrono>
#include <ctime>
#include <stdexcept>

// helper function to create date to check for the expiration of the product
inline std::chrono::system_clock::time_point create_date(int year, int month, int day) {
    std::tm tm = {};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    std::time_t tt = std::mktime(&tm);
    if (tt == -1) {
        throw std::runtime_error("Failed to create date");
    }
    return std::chrono::system_clock::from_time_t(tt);
}

// Different properties of products like Shippable and Expirable

// --- Property Base Class ---
class Property {
public:
    virtual ~Property() = default;
};

// --- Concrete Properties ---
class Shippable : public Property {
public:
    double weight;
    Shippable(double w);
};

class Expirable : public Property {
public:
    std::chrono::system_clock::time_point expirationDate;
    Expirable(int year, int month, int day);
    bool isExpired() const;
};

#endif // PROPERTY_H