#pragma once
#include<set>
#include "PayCheck.h"

class PurchaseHistory
{
public:
	enum Exprenses {
		OneTime,Periodic,Permament
	};

	PurchaseHistory();
	~PurchaseHistory();

	void addCheck(PayCheck*);
	double averageConsumptionFor3Month();
	std::set<PurchaseItem*> theMostExpansivePurches();

private:
	int latestMonth();

	std::vector<PayCheck*> checks;
	//std::map<Product::ProductType,double> 
};

