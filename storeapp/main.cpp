#include <iostream>
#include "Product.h"
#include "Invoice.h"

int main() {
    Invoice invoice;

    // Adding products manually (you can replace this with user input)
    Product p1("Milk", 1.99, "123456");
    Product p2("Bread", 2.50, "789012");
    Product p3("Eggs", 3.20, "345678");

    invoice.addProduct(p1);
    invoice.addProduct(p2);
    invoice.addProduct(p3);

    invoice.printInvoice();

    return 0;
}
