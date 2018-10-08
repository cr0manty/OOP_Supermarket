#pragma once
#include "PayCheck.h"

class PurchaseHistory
{
public:
	enum Exprenses {
		OneTime,Periodic,Permament
	};

	PurchaseHistory();
	~PurchaseHistory();

	void addCheck(PayCheck);
	void addItem(PurchaseItem, int);
	Date getCheckDate(int) const;

	std::vector<std::pair<Product::ProductType, double>> getPriceBytype();

	//double getOneTypeFullPrice(int,Product::ProductType) const;

	double averageMonthlyConsumption(int, int);

	std::vector<std::pair<Exprenses, int>> getClassificationOfAllProducts();
	std::vector<std::pair<double, PurchaseItem>> getThreeMostExp();



private:
	std::map<int, PayCheck> checks;
	std::map<Exprenses, Product> productsByCategories;
};

