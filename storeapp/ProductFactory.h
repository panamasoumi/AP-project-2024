#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include "Product.h"
#include "ConcreteProduct.h"
#include <string>
#include <stdexcept>
#include <sqlite3.h>
#include <iostream>

class ProductFactory {
public:
    static void initializeDatabase() {
        sqlite3* db;
        int rc = sqlite3_open("supermarket.db", &db);

        if (rc) {
            std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
            return;
        }

        const char* sqlCreateTable = 
            "CREATE TABLE IF NOT EXISTS products ("
            "barcode TEXT PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "price REAL NOT NULL);";

        const char* sqlInsertData = 
            "INSERT OR IGNORE INTO products (barcode, name, price) VALUES "
            "('123456', 'Milk', 1.99), "
            "('789012', 'Bread', 2.50), "
            "('345678', 'Eggs', 3.20);";

        char* errMsg = nullptr;
        rc = sqlite3_exec(db, sqlCreateTable, nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            std::cerr << "SQL error (Create Table): " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }

        rc = sqlite3_exec(db, sqlInsertData, nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            std::cerr << "SQL error (Insert Data): " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }

        sqlite3_close(db);
    }

    static Product* createProduct(const std::string &barcode) {
        sqlite3* db;
        int rc = sqlite3_open("supermarket.db", &db);

        if (rc) {
            std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
            return nullptr;
        }

        std::string sql = "SELECT name, price FROM products WHERE barcode = ?";
        sqlite3_stmt* stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

        if (rc != SQLITE_OK) {
            std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
            return nullptr;
        }

        sqlite3_bind_text(stmt, 1, barcode.c_str(), -1, SQLITE_STATIC);

        std::string name;
        double price;
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            price = sqlite3_column_double(stmt, 1);
        } else {
            std::cerr << "Product not found or query error: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return nullptr;
        }

        sqlite3_finalize(stmt);
        sqlite3_close(db);

        return new ConcreteProduct(name, price, barcode);
    }
};

#endif

