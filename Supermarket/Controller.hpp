#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_

/*****************************************************************************/

#include <string>
#include "PurchaseHistory.h"

/*****************************************************************************/

class Controller
{
public:

/*-----------------------------------------------------------------*/

	Controller();

	Controller ( const Controller & ) = delete;
	
	Controller & operator = ( const Controller & ) = delete;

	~Controller();

/*-----------------------------------------------------------------*/

	void createPurchaseItem(std::string const &, double, Product::ProductType, int);

	double getProductPrice(std::string const &) const;

	int getProductAmount(std::string const &) const;

	Product::ProductType getProductType(std::string const &) const;

	/*-----------------------------------------------------------------*/

	int createCheck(const char*);

	Date getCheckDate(int) const;

	void addPurchaseToCheck(int,std::string const &);

	/*-----------------------------------------------------------------*/

	double averageMonthlyConsumption();

	std::map<PurchaseItem*, double> mostFrequentlyPurchased();

	std::map<Product::ProductType, double> lastMonthExpensesByCategory();

	std::vector<PurchaseItem*> threeMostExpensiveCostsForTheHistory();

	std::vector<double> classify();

	double prediction();

	/*-----------------------------------------------------------------*/

	std::vector<PurchaseItem*> getPurchaseItems();

	

private:

	std::vector<PurchaseItem*> products;
	PurchaseHistory *checkList;

	int id;
};



/*****************************************************************************/

#endif //  _CONTROLLER_HPP_
