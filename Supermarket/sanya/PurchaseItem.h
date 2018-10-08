#pragma once
#include "Product.h"

class PurchaseItem
{
public:
	PurchaseItem(std::string const &, double, Product::ProductType, int);
	~PurchaseItem();

	std::string getName() const;
	double getAmount() const;
	double calculatingTheCost();
	double getFullPrice() const;
	Product getProduct() const;

private:
	Product product;
	double amount;
	double price;

};
std::ostream& operator<<(std::ostream&,PurchaseItem*);
