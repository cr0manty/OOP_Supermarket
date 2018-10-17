#include "controller.hpp"
#include "messages.hpp"

Controller::Controller() : id(0)
{
	checkList = new PurchaseHistory;
}

Controller::~Controller()
{
	for (auto i : products)
		delete i;
}

void Controller::createPurchaseItem(std::string const & _name, double _price, Product::ProductType _type, int _amount)
{
	PurchaseItem *product = new PurchaseItem(_name, _price, _type, _amount);

	products.push_back(product);
}

double Controller::getProductPrice(std::string const &_name) const
{
	for (auto i : products)
		if (i->getName() == _name)
			return i->getProduct()->getPrice();

	throw std::logic_error(Messages::ProductNotFound);
}

double Controller::getProductAmount(std::string const & _name) const
{
	for (auto i : products)
		if (i->getName() == _name)
			return i->getAmount();

	throw std::logic_error(Messages::ProductNotFound);
}

Product::ProductType Controller::getProductType(std::string const &_name) const
{
	for (auto i : products)
		if (i->getName() == _name)
			return i->getProduct()->getProductType();

	throw std::logic_error(Messages::ProductNotFound);
}

void Controller::addPurchaseToCheck(int _id, std::string const &_name)
{
	for (auto i : products)
		if (i->getName() == _name) {
			checkList->addItem(i, _id);
			return;
		}

	throw std::logic_error(Messages::ProductNotFound);
}

double Controller::averageMonthlyConsumption()
{
	if (checkList->checksSize() == 0)
		throw std::logic_error(Messages::NoPurchase);

	return checkList->averageMonthlyConsumption();
}

std::map<PurchaseItem*, double> Controller::mostFrequentlyPurchased()
{
	if (checkList->checksSize() == 0)
		throw std::logic_error(Messages::NoPurchase);

	return checkList->theMostPurchased();
}

std::map<Product::ProductType, double> Controller::lastMonthExpensesByCategory()
{
	if (checkList->checksSize() == 0)
		throw std::logic_error(Messages::NoPurchase);

	return checkList->getPriceBytype();
}

std::vector<PurchaseItem*> Controller::threeMostExpensiveCostsForTheHistory()
{
	if (checkList->checksSize() == 0)
		throw std::logic_error(Messages::NoPurchase);

	return checkList->theMostExpansivePurches();
}

std::vector<double> Controller::classify()
{
	if (checkList->checksSize() == 0)
		throw std::logic_error(Messages::NoPurchase);

	return checkList->getClassificationOfAllProducts();
}

double Controller::prediction()
{
	if (checkList->checksSize() == 0)
		throw std::logic_error(Messages::NoPurchase);

	return checkList->prediction();
}

std::vector<PurchaseItem*> Controller::getPurchaseItems()
{
	return products;
}


int Controller::createCheck(const char* _date)
{
	if (strlen(_date) < 1)
		throw std::logic_error(Messages::DateEmpty);

	id++;
	PayCheck *newCheck = new PayCheck(_date,id);

	checkList->addCheck(newCheck, id);

	return id;
}

Date Controller::getCheckDate(int _id) const
{
	return checkList->getCheckDate(_id);
}
