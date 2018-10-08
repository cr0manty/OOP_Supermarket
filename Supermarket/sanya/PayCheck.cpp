#include "PayCheck.h"

PayCheck::PayCheck( const char* _yyyyMMDDHHMN,int _id) : id(_id), date(_yyyyMMDDHHMN)
{

}

PayCheck::~PayCheck()
{
}

void PayCheck::addPurchaseItem(PurchaseItem *_pi)
{
	products.push_back(_pi);
}

int PayCheck::getId() const
{
	return id;
}

Date PayCheck::getDate() const
{
	return date;
}

double PayCheck::getCheckFullPrice()
{
	double fullPrice = 0.0;

	for (auto i : products)
		fullPrice += i->getFullPrice();

	return fullPrice;
}

int PayCheck::getItemsInCheck()
{
	return products.size();
}

std::vector<PurchaseItem*> PayCheck::getAllItemInCheck()
{
	return products;
}





