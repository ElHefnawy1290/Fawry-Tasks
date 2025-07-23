//
// Created by AMR on 7/8/2025.
//

// Book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <stdexcept>

class Book {
protected:
    std::string ISBN;
    std::string title;
    int year;
    double price;

public:
    Book(std::string ISBN, std::string title, int year, double price);
    virtual ~Book() = default;

    virtual double buy(int quantity, const std::string& email, const std::string& address) = 0;

    void setISBN(const std::string &ISBN);
    void setTitle(const std::string &title);
    void setYear(int year);
    void setPrice(double price);
    std::string getISBN() const;
    std::string getTitle() const;
    int getYear() const;
    double getPrice() const;
};

#endif //BOOK_H
