#ifndef INVOICE_H
#define INVOICE_H

#include "Product.h"
#include <vector>
#include <iostream>

class Invoice {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void printInvoice() const {
        double total = 0.0;
        std::cout << "Invoice:" << std::endl;
        std::cout << "----------------------------" << std::endl;
        for (const auto& product : products) {
            std::cout << "Barcode: " << product.getBarcode()
                      << ", Name: " << product.getName()
                      << ", Price: " << product.getPrice() << std::endl;
            total += product.getPrice();
        }
        std::cout << "----------------------------" << std::endl;
        std::cout << "Total: " << total << std::endl;
    }
};

#endif

