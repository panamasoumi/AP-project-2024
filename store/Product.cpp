#include "Product.hpp"
#include <iostream>

BarcodeProduct::BarcodeProduct(std::string name, double price, std::string barcode)
    : name(name), price(price), barcode(barcode) {}

void BarcodeProduct::printInfo() {
    std::cout << "Name: " << name << ", Barcode: " << barcode << ", Price: " << price << std::endl;
}

std::string BarcodeProduct::getName() {
    return name;
}

double BarcodeProduct::getPrice() {
    return price;
}

std::string BarcodeProduct::getBarcode() {
    return barcode;
}
