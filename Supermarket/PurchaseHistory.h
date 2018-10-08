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

	Date getCheckDate(int) const;
	double prediction();
	double averageMonthlyConsumption();
	int checksSize() const;
	std::map<Product::ProductType, double> getPriceBytype();
	std::map<PurchaseItem*, double> theMostPurchased();
	std::vector<double> getClassificationOfAllProducts(int = 0);
	std::vector<PurchaseItem*> theMostExpansivePurches();
	void addCheck(PayCheck*, int);
	void addItem(PurchaseItem*, int);

private:
	std::map<PurchaseItem*, int> products;
	std::vector<PayCheck*> checks;

	int latestMonth();
	int latestYear();
	void addProduct(PurchaseItem*);

};

