//
// Created by AMR on 7/8/2025.
//

#ifndef QUANTUM_SOURCES_H
#define QUANTUM_SOURCES_H

#include "Book.h"
#include <map>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

class QuantumBookstore {
public:
    void addBook(Book* book);

    double buyBook(const std::string& isbn, int quantity, const std::string& email, const std::string& address);
    std::vector<std::string> removeOutdatedBooks(int years);

private:
    std::pmr::unordered_map<std::string, Book*> inventory;
};

#endif //QUANTUM_SOURCES_H
