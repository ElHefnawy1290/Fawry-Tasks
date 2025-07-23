//
// Created by AMR on 7/8/2025.
//

#include "Book.h"

Book::Book(std::string ISBN, std::string title, int year, double price) : ISBN(std::move(ISBN)), title(std::move(title)), year(year), price(price){}

void Book::setISBN(const std::string &ISBN) {
    this -> ISBN = ISBN;
}
void Book::setTitle(const std::string &title) {
    this -> title = title;
}
void Book::setYear(int year) {
    this -> year = year;
}
void Book::setPrice(double price) {
    this -> price = price;
}

std::string Book::getISBN() const {
    return ISBN;
}
std::string Book::getTitle() const {
    return title;
}
int Book::getYear() const {
    return year;
}
double Book::getPrice() const {
    return price;
}

