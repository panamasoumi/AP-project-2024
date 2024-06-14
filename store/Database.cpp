#include "Database.hpp"

void Database::addProduct(Product* product) {
    products[product->getBarcode()] = product;
}

Product* Database::getProduct(std::string barcode) {
    if (products.find(barcode) != products.end()) {
        return products[barcode];
    } else {
        return nullptr;
    }
}
