#include "controller.hpp"
#include "messages.hpp"

Controller::Controller() : id(0)
{

}

Controller::~Controller()
{

}

void Controller::createPurchaseItem(std::string const & _name, double _price, Product::ProductType _type, int _amount)
{
	PurchaseItem product(_name, _price, _type, _amount);

	products.emplace(_name, product);
}

double Controller::getProductPrice(std::string const &_name) const
{
	return products.find(_name)->second->getProduct().getPrice();
}

double Controller::getProductAmount(std::string const & _name) const
{
	return products.find(_name)->second->getAmount();
}

Product::ProductType Controller::getProductType(std::string const &_name) const
{
	return products.find(_name)->second->getProduct().getProductType();
}


void Controller::addPurchaseToCheck(int _id, std::string const &_name)
{
	id++;

	checkList->addCheck(products.find(_name),_id);
}

double Controller::averageMonthlyConsumption()
{
	return checkList->averageConsumptionFor3Month();
}

//std::vector<std::pair<Product::ProductType, double>> Controller::lastMonthExpensesByCategory(int _thisMonth)
//{
//	std::vector<std::pair<Product::ProductType, double>>  category(5);
//
//	/*category[0] = ;
//	category[1] = ;
//	category[2] = ;
//	category[3] = ;
//	category[4] = ;
//*/
//	return category;
//}

int Controller::createCheck(const char* _date)
{
	if (strlen(_date) <1)
		throw std::logic_error(Messages::DateEmpty);

	id++;
	PayCheck *newCheck = new PayCheck(_date,id);

	checkList->addCheck(newCheck);

	return id;
}

Date Controller::getCheckDate(int _id) const
{
	return checkList->getCheckDate(_id);
}
