#include "PurchaseHistory.h"
#include <algorithm>



PurchaseHistory::PurchaseHistory()
{
}


PurchaseHistory::~PurchaseHistory()
{
	for (auto i : checks)
		delete i;

	for (auto j : products)
		delete j.first;
}

void PurchaseHistory::addCheck(PayCheck *_check, int _id)
{
	checks.push_back(_check);
}

void PurchaseHistory::addItem(PurchaseItem *_product, int _id)
{
	for (auto i : checks)
		if (i->getId() == _id)
			i->addPurchaseItem(_product);

	addProduct(_product);
}

Date PurchaseHistory::getCheckDate(int _id) const
{
	for (auto i : checks)
		if (i->getId() == _id)
			return i->getDate();
}

std::vector<PurchaseItem*> PurchaseHistory::theMostExpansivePurches()
{
	std::vector<PurchaseItem*> theMostExpansive;
	for (int size = 0; size < 3; size++) {
		PurchaseItem* maxPrice = checks[0]->getAllItemInCheck()[0];
		for (auto i : checks) {
			std::vector<PurchaseItem*> allItems = i->getAllItemInCheck();
			for (auto j : allItems)
				if (maxPrice->getFullPrice() < j->getFullPrice() &&
					std::find(theMostExpansive.begin(), theMostExpansive.end(), j) == theMostExpansive.end())
					maxPrice = j;
		}
		theMostExpansive.push_back(maxPrice);
	}

	return theMostExpansive;
}

std::map<Product::ProductType, double> PurchaseHistory::getPriceBytype()
{
	std::map<Product::ProductType, double> priceByType;

	for (auto i : checks)
		if (i->getDate().getMonth() == latestMonth())
			for (auto j : i->getAllItemInCheck())
			{
				if (priceByType.find(j->getProduct()->getProductType()) == priceByType.end())
					priceByType.emplace(j->getProduct()->getProductType(), j->getFullPrice());
				else
					priceByType.at(j->getProduct()->getProductType()) += j->getFullPrice();
			}

	return priceByType;
}

std::map<PurchaseItem*, double> PurchaseHistory::theMostPurchased()
{
	std::map<PurchaseItem*, double> topPurchasedItems;

	/*for (int i = 0; i < 5; i++){
		PurchaseItem* max = products.at(1).first;
		for (auto j : products)
			if (j.first > max && topPurchasedItems.find(j.first) == topPurchasedItems.end())
				max = j.first;
		topPurchasedItems.emplace(max, products.find(max)->second * products.find(max)->first->getFullPrice());
	}*/

	return topPurchasedItems;
}

double PurchaseHistory::averageMonthlyConsumption()
{
	double averageConsumption = 0;

	for (auto i : checks)
		if (i->getDate().getMonth() > latestMonth() - 3 && i->getDate().getMonth() <= latestMonth() && 
			i->getDate().getYear() == latestYear())
			averageConsumption += i->getCheckFullPrice();

	return averageConsumption / 3;
}

std::vector<double> PurchaseHistory::getClassificationOfAllProducts(int _period)
{
	std::vector<double> classification(3);
	for (auto i : products)
	{
		int popular = 0;
		for (auto j : checks) {
			std::vector<PurchaseItem*> itemList = j->getAllItemInCheck();
			if (!_period && std::find(itemList.begin(), itemList.end(), i.first) != itemList.end())
				popular++;

			if (_period && j->getDate().getMonth() > _period - 3 && j->getDate().getMonth() <= _period &&
				std::find(itemList.begin(), itemList.end(), i.first) != itemList.end() && j->getDate().getYear() == latestYear())
				popular++;
		}

		if (popular >= checks.size() * 0.8)
			classification[0] += i.first->getFullPrice() * i.second;

		if (checks.size() > 3 && popular < 3 && popular > 1)
			classification[1] += i.first->getFullPrice() * i.second;

		if (popular == 1)
			classification[2] += i.first->getFullPrice() * i.second;
	}
	
	return classification;
}

double PurchaseHistory::prediction()
{
	double predict = 0;
	predict += getClassificationOfAllProducts()[0];
	predict += getClassificationOfAllProducts(latestMonth() - 3)[1] / 3;

	return predict;
}

int PurchaseHistory::checksSize() const
{
	return checks.size();
}

int PurchaseHistory::latestMonth()
{
	int lastMonth = 0;

	for (auto i : checks)
		if (lastMonth < i->getDate().getMonth())
			lastMonth = i->getDate().getMonth();

	return lastMonth;
}

int PurchaseHistory::latestYear()
{
	int latestYear = 0;

	for (auto i : checks)
		if (latestYear < i->getDate().getYear())
			latestYear = i->getDate().getYear();

	return latestYear;
}


void PurchaseHistory::addProduct(PurchaseItem* _product)
{
	if (products.find(_product) != products.end()) {
		products.at(_product)++;
		return;
	}

	products.emplace(_product, 1);
}