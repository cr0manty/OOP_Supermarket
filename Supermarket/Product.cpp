#include "Product.h"


Product::Product(std::string const &_name, double _price, ProductType _type) : name(_name), price(_price), type(_type)
{
	if (name.empty())
		throw std::logic_error(Messages::ProductNameIsEmpty);

	if (price < 1)
		throw std::logic_error(Messages::NonPositivePrice);
}


std::string Product::getName() const
{
	return name;
}

double Product::getPrice() const
{
	return price;
}

Product::ProductType Product::getProductType() const
{
	return type;
}

