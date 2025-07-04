#include "Customer.h"

Customer::Customer(std::string name, double balance) : name(std::move(name)), balance(balance) {}

std::string Customer::getName() const {
  return name;
}

double Customer::getBalance() const {
  return balance;
}

void Customer::setName(const std::string &name) {
    this -> name = name;
}

void Customer::setBalance(double balance) {
    this -> balance = balance;
}

// Pay the checkout from Customer's balance
void Customer::deductFromBalance(double amount) {
    if (amount > 0 && amount <= balance)
        balance -= amount;
}