#ifndef PRODUCT_FACTORY_HPP
#define PRODUCT_FACTORY_HPP

#include "Product.hpp"
#include <string>

// Abstract Factory
class ProductFactory {
public:
    virtual Product* createProduct(std::string name, double price, std::string barcode) = 0;
};

// Concrete Factory
class BarcodeProductFactory : public ProductFactory {
public:
    Product* createProduct(std::string name, double price, std::string barcode) override;
};

#endif // PRODUCT_FACTORY_HPP
