#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Product.hpp"
#include <map>

// Mock Database
class Database {
private:
    std::map<std::string, Product*> products;
public:
    void addProduct(Product* product);
    Product* getProduct(std::string barcode);
};

#endif // DATABASE_HPP
