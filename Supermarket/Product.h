#pragma once
#include <map>
#include <string>
#include "Messages.hpp"

class Product
{

public:
	enum ProductType {
		Food,Chemicals, 
		Hygiene,Goods, 
		OtherGoods
	};

	Product(std::string const &, double, ProductType);

	double getPrice() const;
	ProductType getProductType() const;
	std::string getName() const;

private:
	std::string name;
	double price;
	ProductType type;


};

