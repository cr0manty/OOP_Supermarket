#include "PurchaseItem.h"



PurchaseItem::PurchaseItem(std::string const & _name, double _price, Product::ProductType _type, int _amount) : amount(_amount)
{
	if (amount < 1)
		throw std::logic_error(Messages::NonPositiveAmount);

	product = new Product(_name, _price, _type);
	fullPrice = calculatingTheCost();
}

PurchaseItem::~PurchaseItem()
{
	delete product;
}

std::string PurchaseItem::getName() const
{
	return product->getName();
}

double PurchaseItem::getAmount() const
{
	return amount;
}

double PurchaseItem::calculatingTheCost()
{
	return amount * product->getPrice();
}

double PurchaseItem::getFullPrice() const
{
	return fullPrice;
}

Product* PurchaseItem::getProduct() const
{
	return product;
}
