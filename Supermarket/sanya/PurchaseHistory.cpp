#include "PurchaseHistory.h"



PurchaseHistory::PurchaseHistory()
{
}


PurchaseHistory::~PurchaseHistory()
{
	for (auto i : checks)
		delete i;
}

void PurchaseHistory::addCheck(PayCheck*)
{
}

double PurchaseHistory::averageConsumptionFor3Month()
{
	double averageConsumption = 0.0;

	for (int i = 0; i < checks.size(); i++) {
		if (checks[i]->getDate().getMonth() <= latestMonth() - 3)
			averageConsumption += checks[i]->getCheckFullPrice();
	}


	return averageConsumption / 3;
}

std::set<PurchaseItem*> PurchaseHistory::theMostExpansivePurches()
{
	std::set<PurchaseItem*> theMostExpansive;

	for (int k = 0; k < 3; k++) {
		PurchaseItem *maxPricePurches = checks[0]->getAllItemInCheck().at(0);

		for (int i = 0; i < checks.size(); i++) {

			std::vector<PurchaseItem*> currentPurchesItem = checks[i]->getAllItemInCheck();

			for (int j = 0; j < checks[i]->getItemsInCheck(); j++) {
				if (currentPurchesItem[j]->getFullPrice() > maxPricePurches->getFullPrice() &&
					theMostExpansive.find(currentPurchesItem[j]) != theMostExpansive.end())
					maxPricePurches = currentPurchesItem[j];
			}
		}
	}

	for (auto i : theMostExpansive)
		std::cout << i << std::endl;

}

int PurchaseHistory::latestMonth()
{
	int lastMonth = checks[0]->getDate().getMonth();

	for (int i = 0; i < checks.size(); i++) {
		if (lastMonth < checks[i]->getDate().getMonth())
			lastMonth = checks[i]->getDate().getMonth();
	}

	return lastMonth;
}

