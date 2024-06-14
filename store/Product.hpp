#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

// Abstract Product
class Product {
public:
    virtual void printInfo() = 0;
    virtual std::string getName() = 0;
    virtual double getPrice() = 0;
    virtual std::string getBarcode() = 0;
};

// Concrete Product
class BarcodeProduct : public Product {
private:
    std::string name;
    double price;
    std::string barcode;
public:
    BarcodeProduct(std::string name, double price, std::string barcode);

    void printInfo() override;
    std::string getName() override;
    double getPrice() override;
    std::string getBarcode() override;
};

#endif // PRODUCT_HPP
