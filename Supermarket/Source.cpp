#include <iostream>
#include <cassert>
#include "Controller.hpp"
#include "Messages.hpp"
using namespace std;

int main()
{
	Controller c;
	c.createPurchaseItem("Bananas", 4.5, Product::Food, 5);
	c.createPurchaseItem("Watermelon", 10.5, Product::Food, 3);
	c.createPurchaseItem("Bleach", 11.9, Product::Chemicals, 3);
	c.createPurchaseItem("ToothPaste", 50.5, Product::Hygiene, 13);
	c.createPurchaseItem("Soap", 25.5, Product::Hygiene, 1);
	c.createPurchaseItem("Pants", 4.5, Product::OtherGoods, 23);
	c.createPurchaseItem("Sausages", 4.5, Product::Food, 34);
	c.createPurchaseItem("Computer", 20000, Product::Goods, 2);
	c.createPurchaseItem("Potato", 2.5, Product::Food, 45);
	c.createPurchaseItem("CinemaTicket", 50, Product::Goods, 1);
	c.createPurchaseItem("Cupboard", 15999, Product::OtherGoods, 1);
	c.createPurchaseItem("Meet", 100, Product::Food, 9);


	std::vector<double> check{ 41778.0, 0.0, 0.0 };
	assert(c.averageMonthlyConsumption(8) == check);

	getchar();
	return 0;
}