//
// Created by AMR on 7/8/2025.
//

#include "Quantum_book_store.h"
#include "Book_types.h"
#include <iostream>
#include <iomanip>

class QuantumBookstoreFullTest {
public:
    static void runAllTests() {
        std::cout << std::string(60, '=') << std::endl;
        std::cout << "     Running Book Store tests" << std::endl;
        std::cout << std::string(60, '=') << std::endl << std::endl;

        QuantumBookstore bookstore;
        std::cout << std::fixed << std::setprecision(2);

        // 1. Add different types of books.
        // The bookstore accepts them all because they are all children of "Book".
        PaperBook *paperbook1 = new PaperBook("978-0321765723", "The C++ Programming Language", 2013, 60.50, 10);
        EBook *EBook1 = new EBook("978-0134685991", "Effective Java", 2018, 40.00, "PDF");
        ShowcaseBook *ShowcaseBook1 = new ShowcaseBook("999-00000000", "Quantum Showcase", 2024);
        bookstore.addBook(paperbook1);
        bookstore.addBook(EBook1);
        bookstore.addBook(ShowcaseBook1);
        std::cout << std::endl;

        // 2. Test buying books.
        std::cout << "--- Testing Buys ---" << std::endl;
        try {
            // testing if The bookstore calls the correct buy() method for each type automatically.
            bookstore.buyBook("978-0321765723", 1, "", "123 Main St, Anytown, USA");
            bookstore.buyBook("978-0134685991", 1, "customer@example.com", "");
            bookstore.buyBook("999-00000000", 1, "", ""); // This one will fail as intended.
        }
        catch (const std::exception& e) {
            std::cerr << "Error during purchase: " << e.what() << std::endl;
        }
    }
};
