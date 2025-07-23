#include "Book_types.h"
#include "Services.h"
#include <iostream>

// --- PaperBook Implementation ---
PaperBook::PaperBook(const std::string& isbn, const std::string& title, int year, double price, int stock)
    : Book(isbn, title, year, price), stock(stock) {}

double PaperBook::buy(int quantity, const std::string& email, const std::string& address) {
    if (quantity > stock) {
        throw std::runtime_error("Quantum book store: Not enough paper books in stock.");
    }
    stock -= quantity;
    ShippingService::send(this->title, address);
    return this->price * quantity;
}

// --- EBook Implementation ---
EBook::EBook(const std::string& isbn, const std::string& title, int year, double price, const std::string& filetype)
    : Book(isbn, title, year, price), filetype(std::move(filetype)) {}

double EBook::buy(int quantity, const std::string& email, const std::string& address) {
    MailService::send(this->title, email);
    return this->price * quantity;
}

// --- ShowcaseBook Implementation ---
ShowcaseBook::ShowcaseBook(const std::string& isbn, const std::string& title, int year)
    : Book(isbn, title, year, 0.0) {}

double ShowcaseBook::buy(int quantity, const std::string& email, const std::string& address) {
    throw std::logic_error("Quantum book store: Showcase books are not for sale.");
}