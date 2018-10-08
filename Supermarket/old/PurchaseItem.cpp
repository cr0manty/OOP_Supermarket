#include "PurchaseItem.h"



PurchaseItem::PurchaseItem(std::string const & _name, double _price, Product::ProductType _type, int _amount) : amount(_amount), product(_name, _price, _type)
{
	if (amount < 1)
		throw std::logic_error(Messages::NonPositiveAmount);
}

PurchaseItem::~PurchaseItem()
{
}

std::string PurchaseItem::getName() const
{
	return product.getName();
}

double PurchaseItem::getAmount() const
{
	return amount;
}

double PurchaseItem::calculatingTheCost()
{
	return amount * product.getPrice();
}

double PurchaseItem::getFullPrice() const
{
	return price;
}

Product PurchaseItem::getProduct() const
{
	return product;
}
