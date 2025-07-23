//
// Created by AMR on 7/8/2025.
//

#ifndef SERVICES_H
#define SERVICES_H
#include <iostream>

class ShippingService {
public:
    static void send(const std::string& bookTitle, const std::string& address) {
        std::cout << "Quantum book store: Shipping '" << bookTitle << "' to " << address << "." << "\n";
    }
};

class MailService {
public:
    static void send(const std::string& bookTitle, const std::string& email) {
        std::cout << "Quantum book store: Sending '" << bookTitle << "' to " << email << "." << "\n";
    }
};

#endif //SERVICES_H
