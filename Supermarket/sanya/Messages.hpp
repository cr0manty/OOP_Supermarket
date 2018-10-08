// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _MESSAGES_HPP_
#define _MESSAGES_HPP_

/*****************************************************************************/

namespace Messages
{

/*-----------------------------------------------------------------*/
	const char * const ProductNameIsEmpty		= "Product name may not be empty";
	const char * const NonPositivePrice			= "Product price can't be negative or zero amount of money";
	const char * const NonPositiveAmount		= "Product amount can't be negative or zero amount of money";
	const char * const UnknownCheckID			= "Check ID is not found";
	const char * const ProductNameNotUnique     = "Product name must be unique";
	const char * const DateEmpty				= "Date cant be empty";
	const char * const DateWrongFormat			= "Date wrong format";

	/*const char * const NegativeInitialBalance   = "Cannot create account with negative initial balance";
	const char * const NegativeOverdraft        = "Cannot create account with negative overdraft setting";
	const char * const NonPositiveDeposit       = "Cannot deposit negative or zero amount of money";
	const char * const NonPositiveWithdrawal    = "Cannot withdraw negative or zero amount of money";
	const char * const NonPositiveTransfer      = "Cannot transfer negative or zero amount of money";
	const char * const WithdrawalLimitExceeded  = "Withdrawal limit exceeded";
*/
/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


#endif // _MESSAGES_HPP_
