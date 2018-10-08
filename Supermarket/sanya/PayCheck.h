#pragma once
#include "PurchaseItem.h"
#include "Date.hpp"
#include <vector>

class PayCheck
{
public:
	PayCheck(const char *, int);
	~PayCheck();

	void addPurchaseItem(PurchaseItem*);

	int getId() const;
	Date getDate() const;
	double getCheckFullPrice();
	int getItemsInCheck();
	std::vector<PurchaseItem*> getAllItemInCheck();

private:
	int id;
	Date date;
	std::vector<PurchaseItem*> products;
};

