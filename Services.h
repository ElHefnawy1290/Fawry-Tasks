#ifndef SERVICES_H
#define SERVICES_H

// Forward-declarations
class Cart;
class Customer;

class ShippingService {
public:
    double calculateFees(const Cart& cart) const;
    void generateShipmentNotice(const Cart& cart) const;
};

class CheckoutService {
public:
    void checkout(Customer& customer, Cart& cart, const ShippingService& shippingService);
};

#endif