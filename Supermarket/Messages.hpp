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
	const char * const NoPurchase				= "No purchase was made";
	const char * const LessThen3Purchases		= "Less than 3 Purchases was made";
	const char * const CheckNotFound			= "Check with this id not found";
	const char * const ProductNotFound			= "Product with this name not found";
	
/*-----------------------------------------------------------------*/

};


/*****************************************************************************/


#endif // _MESSAGES_HPP_
