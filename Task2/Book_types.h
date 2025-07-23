//
// Created by AMR on 7/8/2025.
//

#ifndef BOOK_TYPES_H
#define BOOK_TYPES_H

#include <ctime>
#include "Book.h"
#include "Services.h"

inline int getCurrentYear() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1900 + ltm->tm_year;
}

class PaperBook : public Book {
public:
    PaperBook(const std::string& isbn, const std::string& title, int year, double price, int stock);
    double buy(int quantity, const std::string& email, const std::string& address) override;
private:
    int stock;
};

class EBook : public Book {
public:
    EBook(const std::string& isbn, const std::string& title, int year, double price, const std::string& filetype);
    double buy(int quantity, const std::string& email, const std::string& address) override;
private:
    std::string filetype;
};

class ShowcaseBook : public Book {
public:
    ShowcaseBook(const std::string& isbn, const std::string& title, int year);
    double buy(int quantity, const std::string& email, const std::string& address) override;
};

#endif //BOOK_TYPES_H
