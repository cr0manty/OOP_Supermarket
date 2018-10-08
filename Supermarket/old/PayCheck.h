#pragma once
#include "PurchaseItem.h"
#include "Date.hpp"
#include <vector>

class PayCheck
{
public:
	PayCheck(const char *, int);
	~PayCheck();

	void addPurchaseItem(PurchaseItem);
	double getFullPriceByType(Product::ProductType);

	int getId() const;
	Date getDate() const;
	double getCheckFullPrice();
	std::vector<std::string> getAllNameInCheck() const;
	

private:
	int id;
	Date date;
	std::vector<PurchaseItem> products;
};

