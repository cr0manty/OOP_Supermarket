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

	double getProductAmount(std::string const &) const;

	Product::ProductType getProductType(std::string const &) const;

	/*-----------------------------------------------------------------*/
	int createCheck(const char*);

	Date getCheckDate(int) const;

	void addPurchaseToCheck(int,std::string const &);

	/*-----------------------------------------------------------------*/

	double averageMonthlyConsumption();

	//std::vector<std::string>  mostFrequentlyPurchased();

	//std::vector<std::pair<Product::ProductType, double>> lastMonthExpensesByCategory(int);

	//std::map<std::string,int> threeMostExpensiveCostsForTheHistory();

	//void classify();

	//void prognoz();

private:

	std::map<std::string, PurchaseItem*> products;
	PurchaseHistory *checkList;

	int id;
};


/*****************************************************************************/

#endif //  _CONTROLLER_HPP_
