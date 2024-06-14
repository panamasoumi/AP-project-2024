#include "ProductFactory.hpp"

Product* BarcodeProductFactory::createProduct(std::string name, double price, std::string barcode) {
    return new BarcodeProduct(name, price, barcode);
}
