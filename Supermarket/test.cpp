#include "controller.hpp"
#include "messages.hpp"

#include "testslib.hpp"

/*****************************************************************************/

void createProducts(Controller &c)
{
	c.createPurchaseItem("Bananas", 4.5, Product::Food, 5);
	c.createPurchaseItem("Watermelon", 10.5, Product::Food, 3);
	c.createPurchaseItem("Bleach", 11.9, Product::Chemicals, 3);
	c.createPurchaseItem("ToothPaste", 50.5, Product::Hygiene, 13);
	c.createPurchaseItem("Soap", 25.5, Product::Hygiene, 1);
	c.createPurchaseItem("Pants", 4.5, Product::OtherGoods, 23);
	c.createPurchaseItem("Sausages", 4.5, Product::Food, 34);
	c.createPurchaseItem("Computer", 20000, Product::Goods, 2);
	c.createPurchaseItem("Potato", 2.5, Product::Food, 45);
	c.createPurchaseItem("CinemaTicket", 50, Product::Goods, 1);
	c.createPurchaseItem("Cupboard", 15999, Product::OtherGoods, 1);
	c.createPurchaseItem("Meet", 100, Product::Food, 9);
}

void createBills(Controller &c)
{
	createProducts(c);

	int uniqId1 = c.createCheck("2018/08/24/18:00:01");
	c.addPurchaseToCheck(uniqId1, "Bananas");
	c.addPurchaseToCheck(uniqId1, "CinemaTicket");
	c.addPurchaseToCheck(uniqId1, "Potato");
	c.addPurchaseToCheck(uniqId1, "Meet");
	c.addPurchaseToCheck(uniqId1, "Soap");

	int uniqId2 = c.createCheck("2018/05/04/19:04:51");
	c.addPurchaseToCheck(uniqId2, "Sausages");
	c.addPurchaseToCheck(uniqId2, "Computer");
	c.addPurchaseToCheck(uniqId2, "ToothPaste");
	c.addPurchaseToCheck(uniqId2, "Meet");
	c.addPurchaseToCheck(uniqId2, "Pants");

	int uniqId3 = c.createCheck("2018/09/09/19:04:51");
	c.addPurchaseToCheck(uniqId3, "Sausages");

	int uniqId4 = c.createCheck("2018/01/08/19:04:51");
	c.addPurchaseToCheck(uniqId4, "ToothPaste");
	c.addPurchaseToCheck(uniqId4, "Meet");
	c.addPurchaseToCheck(uniqId4, "Cupboard");

	int uniqId5 = c.createCheck("2018/06/08/19:04:51");
	c.addPurchaseToCheck(uniqId5, "Meet");
	c.addPurchaseToCheck(uniqId5, "Pants");

	int uniqId6 = c.createCheck("2018/12/08/19:04:51");
	c.addPurchaseToCheck(uniqId6, "Sausages");
	c.addPurchaseToCheck(uniqId6, "Computer");
	c.addPurchaseToCheck(uniqId6, "Meet");

	int uniqId7 = c.createCheck("2018/01/08/19:04:51");
	c.addPurchaseToCheck(uniqId7, "ToothPaste");
	c.addPurchaseToCheck(uniqId7, "Meet");

}

/*****************************************************************************/

DECLARE_OOP_TEST ( test_create_products )
{
	Controller c;
	c.createPurchaseItem("Bananas", 4.5, Product::Food, 5);

	assert(c.getProductPrice("Bananas") == 4.5);
	assert(c.getProductType("Bananas") == Product::Food);
	assert(c.getProductAmount("Bananas") == 5 );
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_create_products_empty_name_fails)
{
	Controller c;

	ASSERT_THROWS(
		c.createPurchaseItem("", 4.5, Product::Food, 5),
		Messages::ProductNameIsEmpty
	);
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_create_products_negative_price)
{
	Controller c;

	ASSERT_THROWS(
		c.createPurchaseItem("Bananas", -1, Product::Food, 5),
		Messages::NonPositivePrice
	);
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_create_products_negative_amount)
{
	Controller c;

	ASSERT_THROWS(
		c.createPurchaseItem("Bananas", 45, Product::Food, -2),
		Messages::NonPositiveAmount
	);
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_create_check)
{
	Controller c;
	int checkID = c.createCheck("2018/08/24/18:00:01");

	assert(c.getCheckDate(checkID) == Date("2018/08/24/18:00:01"));
	
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_empty_date)
{
	Controller c;

	ASSERT_THROWS(
		c.createCheck(""),
		Messages::DateEmpty
	);
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_add_product_without_creating_product)
{
	Controller c;
	int checkID = c.createCheck("2018/08/24/18:00:01");

	ASSERT_THROWS(
		c.addPurchaseToCheck(checkID, "Sausages"),
		Messages::ProductNotFound
	);
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_unique_product_name)
{
	Controller c;
	int checkID = c.createCheck("2018/08/24/18:00:01");

	c.createPurchaseItem("Sausages", 4.5, Product::Food, 34);
	c.addPurchaseToCheck(checkID, "Sausages");
	
	ASSERT_THROWS(
		c.addPurchaseToCheck(checkID, "Sausages"),
		Messages::ProductNameNotUnique
	);
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_date_format)
{
	Controller c;

	ASSERT_THROWS(
		c.createCheck("2018082418:00:01"),
		Messages::DateWrongFormat
	);
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_the_average_monthly_consumption_for_3_month)
{
	Controller c;
	createBills(c);

	assert(c.averageMonthlyConsumption() == 13684.333333333334);
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_the_average_monthly_consumption_for_3_month_without_products)
{
	Controller c;
	int checkID = c.createCheck("2018/08/24/18:00:01");

	assert(c.averageMonthlyConsumption() == 0);

}

/*****************************************************************************/

DECLARE_OOP_TEST(test_month_price_by_categories)
{
	Controller c;
	createBills(c);

	std::map<Product::ProductType, double> test = c.lastMonthExpensesByCategory();

	assert(test.find(Product::Food)->second == 1053.0);
	assert(test.find(Product::Goods)->second == 40000.0);

}

/*****************************************************************************/

DECLARE_OOP_TEST(test_empty_checklist_categories)
{
	Controller c;
	
	ASSERT_THROWS(
		c.lastMonthExpensesByCategory(),
		Messages::NoPurchase
	);
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_get_product_price_by_type)
{
	Controller c;
	createBills(c);

	std::vector<double> test{5400.0, 80207.0, 16209.5};
	assert(c.classify() == test);
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_get_empty_product_price_by_type)
{
	Controller c;

	ASSERT_THROWS(
		c.lastMonthExpensesByCategory(),
		Messages::NoPurchase
	);
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_prediction)
{
	Controller c;
	createBills(c);

	assert(c.prediction() == 5400.0);
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_get_3_most_esxp_purchases)
{
	Controller c;
	createBills(c);


	std::vector<PurchaseItem*> test = c.threeMostExpensiveCostsForTheHistory();
	int checkID = c.createCheck("2018/08/24/18:00:01");
	for(auto i: c.threeMostExpensiveCostsForTheHistory())
		c.addPurchaseToCheck(checkID, i->getName());
	int testCheck = c.createCheck("2018/08/24/18:00:01");
	c.addPurchaseToCheck(checkID, "Computer");
	c.addPurchaseToCheck(checkID, "Cupboard");
	c.addPurchaseToCheck(checkID, "Meet");
	//assert(== test);
	//assert(test == std::vector<PurchaseItem*>{)
}

/*****************************************************************************/

DECLARE_OOP_TEST(test_get_empty_3_most_esxp_purchases)
{
	Controller c;

	ASSERT_THROWS(
		c.threeMostExpensiveCostsForTheHistory(),
		Messages::NoPurchase
	);
}

/*****************************************************************************/

/*****************************************************************************/

/*****************************************************************************/

/*****************************************************************************/

/*****************************************************************************/

/*****************************************************************************/

/*****************************************************************************/

/*****************************************************************************/

/*****************************************************************************/
