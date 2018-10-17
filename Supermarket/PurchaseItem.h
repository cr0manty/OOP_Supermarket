#pragma once
#include "Product.h"

class PurchaseItem
{
public:
	PurchaseItem(std::string const &, double, Product::ProductType, int);
	~PurchaseItem();

	double getAmount() const;
	double calculatingTheCost();
	double getFullPrice() const;
	Product* getProduct() const;
	std::string getName() const;
	bool operator==(PurchaseItem&);
private:
	Product *product;
	double amount;
	double fullPrice;

};

