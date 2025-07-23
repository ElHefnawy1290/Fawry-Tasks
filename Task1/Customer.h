#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    double balance;
public:
    Customer(std::string name, double balance);
    std::string getName() const;
    double getBalance() const;
    void setName(const std::string &name);
    void setBalance(double balance);
    void deductFromBalance(double amount);
};

#endif