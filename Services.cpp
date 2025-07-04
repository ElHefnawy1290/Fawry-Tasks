#include "Services.h"
#include "Cart.h"
#include "Customer.h"
#include "Product.h" // Needed for getComponent
#include <iostream>
#include <iomanip>

// --- ShippingService ---
double ShippingService::calculateFees(const Cart& cart) const {
    double totalWeight{};
    // computing the total_weight
    for (const auto& item : cart.getItems()) {
        Shippable* shipping = item.first->getProperty<Shippable>(); // check if the item has shippable property
        if (shipping)
            totalWeight += shipping->weight * item.second;
    }
    return totalWeight * 10.0; // Assumption: $10 per kg
}

void ShippingService::generateShipmentNotice(const Cart& cart) const {
    std::cout << "** Shipment notice **\n";
    double totalWeight{};
    bool hasShippableItems{};
    for (const auto& item : cart.getItems()) {
        Product* product = item.first;
        int quantity = item.second;
        Shippable* shipping = product->getProperty<Shippable>(); // check if the item has shippable property
        if (shipping) {
            hasShippableItems = true;
            double itemTotalWeight = shipping->weight * quantity;
            totalWeight += itemTotalWeight;
            std::cout << quantity << "x " << product->getName() << " " << itemTotalWeight * 1000 << "g\n";
        }
    }
    if (hasShippableItems)
        std::cout << "Total package weight " << totalWeight << "kg\n\n";
    else
        std::cout << "No items to ship.\n\n";
}

// --- CheckoutService ---
void CheckoutService::checkout(Customer& customer, Cart& cart, const ShippingService& shippingService) {
    std::cout << "--- Starting Checkout for " << customer.getName() << " ---\n";
    // Handling if the cart is empty
    if (cart.isEmpty()) {
        std::cout << "Error: Cart is empty.\n\n";
        return;
    }

    for (const auto& item : cart.getItems()) {
        Expirable* expiration = item.first->getProperty<Expirable>(); // check if the item has this property
        if (expiration) {
            if (expiration->isExpired()) {
                std::cout << "Error: " << item.first->getName() << " is expired.\n\n";
                return;
            }
        }
    }

    // Calculating Process fees
    double subtotal = cart.calculateSubtotal();
    double shippingFees = shippingService.calculateFees(cart);
    double totalAmount = subtotal + shippingFees;

    if (customer.getBalance() < totalAmount) {
        std::cout << "Error: Insufficient balance. Required: " << totalAmount << ", Available: " << customer.getBalance() << "\n\n";
        return;
    }

    // Print Shipment notice
    shippingService.generateShipmentNotice(cart);

    // print checkout receipt
    std::cout << "** Checkout receipt **\n";
    for (const auto& item : cart.getItems())
        std::cout << item.second << "x " << item.first->getName() << " " << item.first->getPrice() * item.second << "\n";

    std::cout << "----------------------\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Subtotal " << subtotal << "\n";
    std::cout << "Shipping " << shippingFees << "\n";
    std::cout << "Amount " << totalAmount << "\n\n";

    // Process payment
    customer.deductFromBalance(totalAmount);
    for (const auto& item : cart.getItems())
        item.first->reduceQuantity(item.second);

    std::cout << "Payment successful. " << customer.getName()
              << "'s new balance: " << customer.getBalance() << "\n";
    std::cout << "--- Checkout Complete ---\n\n";
}