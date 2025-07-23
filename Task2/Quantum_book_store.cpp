//
// Created by AMR on 7/8/2025.
//

#include "Quantum_book_store.h"
#include "Book_types.h"
#include <iostream>
#include <chrono>

void QuantumBookstore::addBook(Book* book) {
    std::cout << "Quantum book store: Added '" << book->getTitle() << "' to inventory." << std::endl;
    inventory[book->getISBN()] = std::move(book);
}

double QuantumBookstore::buyBook(const std::string& ISBN, int quantity, const std::string& email, const std::string& address) {
    auto it = inventory.find(ISBN);
    if (it == inventory.end())
        throw std::runtime_error("Quantum book store: Book with this ISBN not found.");

    double paidAmount = it->second->buy(quantity, email, address);

    std::cout << "Quantum book store: Successfully purchased '" << it->second->getTitle() << "'. Total paid: $" << paidAmount << std::endl;
    return paidAmount;
}

std::vector<std::string> QuantumBookstore::removeOutdatedBooks(int years) {
    int currentYear = getCurrentYear();

    std::vector<std::string> removedTitles;
    for (auto &[ISBN, Book]: inventory) {
        if (currentYear > Book->getYear() + years) {
            std::cout << "Quantum book store: Removed outdated book '" << Book->getTitle() << "'." << std::endl;
            removedTitles.push_back(Book->getTitle());
            inventory.erase(ISBN);
        }
    }
    return removedTitles;
}