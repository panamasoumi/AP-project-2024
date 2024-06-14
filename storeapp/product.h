#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    double price;
    std::string barcode;

public:
    Product(const std::string& name, double price, const std::string& barcode)
        : name(name), price(price), barcode(barcode) {}

    std::string getName() const { return name; }
    double getPrice() const { return price; }
    std::string getBarcode() const { return barcode; }
};

#endif

