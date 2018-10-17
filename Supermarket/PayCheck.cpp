#include "PayCheck.h"

PayCheck::PayCheck( const char* _yyyyMMDDHHMN,int _id) : id(_id),date(_yyyyMMDDHHMN)
{
}

PayCheck::~PayCheck()
{
	for (auto i : products)
		delete i;
}

void PayCheck::addPurchaseItem(PurchaseItem* _pi)
{
	isProductAlredyBought(_pi->getName());

	products.push_back(_pi);
}

double PayCheck::getFullPriceByType(Product::ProductType _type)
{
	double price = 0;

	for (auto i : products)
		if (i->getProduct()->getProductType() == _type)
			price += i->getFullPrice();

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
		fullPrice += i->getFullPrice();

	return fullPrice;
}

std::vector<PurchaseItem*> PayCheck::getProducts() const
{
	return products;
}

bool PayCheck::isProductAlredyBought(std::string const & _name)
{
	for (auto i : products)
		if (i->getName() == _name)
			throw std::logic_error(Messages::ProductNameNotUnique);
}

std::vector<PurchaseItem*> PayCheck::getAllItemInCheck()
{
	return products;
}

