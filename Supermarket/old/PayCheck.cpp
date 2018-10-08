#include "PayCheck.h"

PayCheck::PayCheck( const char* _yyyyMMDDHHMN,int _id) : id(_id), date(_yyyyMMDDHHMN)
{

}

PayCheck::~PayCheck()
{
}

void PayCheck::addPurchaseItem(PurchaseItem _pi)
{
	products.push_back(_pi);
}

double PayCheck::getFullPriceByType(Product::ProductType _type)
{
	double price = 0;

	for (auto i : products)
		if (i.getProduct().getProductType() == _type)
			price += i.getFullPrice();

	return price;

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
		fullPrice += i.getFullPrice();

	return fullPrice;
}

std::vector<std::string> PayCheck::getAllNameInCheck() const
{
	std::vector<std::string> names;

	for (auto i : products)
		names.push_back(i.getName());

	return names;
}
