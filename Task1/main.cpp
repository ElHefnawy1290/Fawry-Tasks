#include <iostream>
#include <vector>

#include "Product.h"
#include "Customer.h"
#include "Cart.h"
#include "Services.h"
#include "Property.h"

int main() {
    std::vector<Product*> inventory;

    Product* cheese = new Product("Cheese", 100.0, 20);
    cheese->addProperty(new Shippable(0.4));
    cheese->addProperty(new Expirable(2026, 12, 31));
    inventory.push_back(cheese);

    Product* old_milk = new Product("Old Milk", 20.0, 10);
    old_milk->addProperty(new Expirable(2024, 5, 1));
    inventory.push_back(old_milk);

    Product* tv = new Product("TV", 8000.0, 5);
    tv->addProperty(new Shippable(12.5));
    inventory.push_back(tv);

    Product* mobile_scratch_card = new Product("Mobile Scratch Card", 25.0, 100);
    inventory.push_back(mobile_scratch_card);

    // --- Test 1: Successful Checkout ---
    std::cout << "*******************************************\n";
    std::cout << "*** SCENARIO: Successful Checkout       ***\n";
    std::cout << "*******************************************\n";
    Customer customer("Fawry Intern", 10000.0);
    Cart cart1;
    cart1.addProduct(cheese, 2);
    cart1.addProduct(tv, 1);

    ShippingService shippingService;
    CheckoutService checkoutService;
    checkoutService.checkout(customer, cart1, shippingService);

    // --- Test 2: Expired Item in Cart ---
    std::cout << "\n*******************************************\n";
    std::cout << "*** SCENARIO: Expired Item In Cart      ***\n";
    std::cout << "*******************************************\n";
    Cart cart2;
    cart2.addProduct(old_milk, 1);
    checkoutService.checkout(customer, cart2, shippingService);

    // --- Test 3: Cart is Empty ---
    std::cout << "\n*******************************************\n";
    std::cout << "*** SCENARIO: Cart Is Empty      ***\n";
    std::cout << "*******************************************\n";
    Cart Cart3;
    checkoutService.checkout(customer, Cart3, shippingService);

    // --- Test 4: insufficient amount of money ---
    std::cout << "\n*******************************************\n";
    std::cout << "*** SCENARIO: Insufficient balance      ***\n";
    std::cout << "*******************************************\n";
    Cart Cart4;
    Cart4.addProduct(cheese, 5);
    Cart4.addProduct(tv, 1);
    checkoutService.checkout(customer, Cart4, shippingService);

    // --- Test 5: Product out of stock ---
    std::cout << "\n*******************************************\n";
    std::cout << "*** SCENARIO: Product out of stock      ***\n";
    std::cout << "*******************************************\n";
    Cart Cart5;
    Cart5.addProduct(cheese, 21);
    checkoutService.checkout(customer, Cart5, shippingService);

    // Test 6: Another successful checkout with no Shippable item
    std::cout << "\n*******************************************\n";
    std::cout << "*** SCENARIO: Another successful checkout with no Shippable item      ***\n";
    std::cout << "*******************************************\n";
    Cart Cart6;
    Cart6.addProduct(mobile_scratch_card, 1);
    checkoutService.checkout(customer, Cart6, shippingService);

    // Test 7: Last Checkout (insufficient balance)
    std::cout << "\n*******************************************\n";
    std::cout << "*** Last Checkout (insufficient balance)      ***\n";
    std::cout << "*******************************************\n";
    Cart Cart7;
    Cart7.addProduct(cheese, 18);
    checkoutService.checkout(customer, Cart7, shippingService);

    for (Product* p : inventory) {
        delete p;
    }

    return 0;
}