CREATE TABLE products (
    barcode TEXT PRIMARY KEY,
    name TEXT NOT NULL,
    price REAL NOT NULL
);

INSERT INTO products (barcode, name, price) VALUES ('123456', 'Milk', 1.99);
INSERT INTO products (barcode, name, price) VALUES ('789012', 'Bread', 2.50);
INSERT INTO products (barcode, name, price) VALUES ('345678', 'Eggs', 3.20);
INSERT INTO products (barcode, name, price)  VALUES ('989781', 'sauce',2.88);
INSERT INTO products (barcode, name, price) VALUES ('123486','soap',2);
INSERT INTO products (barcode, name, price) VALUES ('989876','beef',5.70);
INSERT INTO products (barcode, name, price) VALUES ('456787','chips',4);
INSERT INTO products (barcode, name, price) VALUES ('345656','oil',3.90)
INSERT INTO products (barcode, name, price) VALUES ('123432','lime',0.89);
INSERT INTO products (barcode, name, price) VALUES ('098767','juice',3.76);
INSERT INTO products (barcode, name, price) VALUES ('455465','red pepper',8.90);