#pragma once
#include "PurchaseItem.h"
#include "Date.hpp"
#include <vector>

class PayCheck
{
public:
	PayCheck(const char *, int);
	~PayCheck();

	double getFullPriceByType(Product::ProductType);
	std::vector<PurchaseItem*> getAllItemInCheck();
	void addPurchaseItem(PurchaseItem*);

	int getId() const;
	Date getDate() const;
	double getCheckFullPrice();
	std::vector<PurchaseItem*> getProducts() const;
private:
	int id;
	Date date;
	std::vector<PurchaseItem*> products;

	bool isProductAlredyBought(std::string const &);
};

