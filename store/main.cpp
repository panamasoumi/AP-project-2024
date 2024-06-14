#include "Product.hpp"
#include "ProductFactory.hpp"
#include "Database.hpp"
#include <iostream>
#include <vector>

int main() {
    BarcodeProductFactory barcodeFactory;
    Database database;

    // Adding products to the database
    Product* product1 = barcodeFactory.createProduct("Milk", 2.5, "1234567890");
    Product* product2 = barcodeFactory.createProduct("Bread", 1.0, "9876543210");

    database.addProduct(product1);
    database.addProduct(product2);

    // Simulating printing invoice
    std::vector<std::string> invoiceBarcodes = {"1234567890", "9876543210"};

    std::cout << "---------- Invoice ----------" << std::endl;
    double totalAmount = 0.0;
    for (const auto& barcode : invoiceBarcodes) {
        Product* product = database.getProduct(barcode);
        if (product != nullptr) {
            product->printInfo();
            totalAmount += product->getPrice();
        } else {
            std::cout << "Product with barcode " << barcode << " not found." << std::endl;
        }
    }

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Total Amount: " << totalAmount << std::endl;

    // Clean up
    delete product1;
    delete product2;

    return 0;
}
 