#include "PurchaseHistory.h"



PurchaseHistory::PurchaseHistory()
{
}


PurchaseHistory::~PurchaseHistory()
{
}

void PurchaseHistory::addCheck(PayCheck _check)
{
	checks.emplace(_check.getId(), _check);
}

void PurchaseHistory::addItem(PurchaseItem _product, int _id)
{
	checks.find(_id)->second.addPurchaseItem(_product);
}

Date PurchaseHistory::getCheckDate(int _id) const
{
	return checks.find(_id)->second.getDate();
}

std::vector<std::pair<Product::ProductType, double>> PurchaseHistory::getPriceBytype()
{
	std::vector<std::pair<Product::ProductType, double>> priceByType(5);
}

//double PurchaseHistory::getOneTypeFullPrice(int _thisMoth, Product::ProductType) const
//{
//	double typePrice = 0;
//	for (auto i : checks)
//		if(i.second.getDate().getMonth() == _thisMoth)
//			if(i.second.getProductType(i.second.getName))
//
//	return typePrice;
//}

double PurchaseHistory::averageMonthlyConsumption(int _todayMonth, int _year)
{
	double MonthlyConsumption = 0;

	for (int i = _todayMonth - 3; i < _todayMonth; i++) {
		double monthMoney = 0;
		for (auto j : checks) 
			if (j.second.getDate().getMonth() == i && j.second.getDate().getYear() == _year)
				monthMoney += j.second.getCheckFullPrice();

		MonthlyConsumption+=monthMoney;

	}

	return MonthlyConsumption / 3;
}

std::vector<std::pair<PurchaseHistory::Exprenses, int>> PurchaseHistory::getClassificationOfAllProducts()
{

	std::vector<std::pair<Exprenses, int>> classification;
	//что-то написать чтоб находило самый популярный товар,ха,изи,да еще и считало цены на популярные и не популярные товары 
	for (auto i : checks)
		//allNames.push_back(i.second.getAllNameInCheck());

	return classification;
}

//std::vector<std::pair<double, PurchaseItem>> PurchaseHistory::getThreeMostExp()
//{
//	std::vector<std::pair<double, PurchaseItem>> products;
//
//	for (auto i : checks)
//		i.second.
//}
