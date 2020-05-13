#include"seller.h"
seller::seller(const char *userName, const char *password, const adress &a) :user(userName, password, a)
{
	SE_setArrays();
}
//_________________________________________________________________________________________________
seller::~seller()
{
	for (int i = 0; i < SE_logicAraayProduct; i++)
		delete SE_arrayOfProduct[i];
	delete[] SE_arrayOfProduct;
	delete[] SE_ArrayOfFeedbacks;
	delete[] SE_arrayOfPurchaseConsumers;
}
//__________________________________________________________________________________________________
void seller::SE_setArrays()
{
	SE_logicFeedbcak = 0;
	SE_physicFeedback = 2;
	SE_ArrayOfFeedbacks = new feedback [SE_physicFeedback];
	SE_physicArrayProduct=2;
	SE_logicAraayProduct = 0;
	SE_arrayOfProduct = new product*[SE_physicArrayProduct];
	SE_physicOfArrayConsumer = 2;
	SE_logicOfArrayconsumers = 0;
	SE_arrayOfPurchaseConsumers = new user*[SE_physicOfArrayConsumer];
}

//_____________________________________________________________________________________________________
void seller::SE_addProduct( product* newProdcut)
{
	if (SE_logicAraayProduct == SE_physicArrayProduct)
	{
		SE_physicArrayProduct *= 2;
		product**tempArray = new product*[SE_physicArrayProduct];
		for (int i = 0; i <= SE_logicAraayProduct; i++)
			tempArray[i] = SE_arrayOfProduct[i];
		delete[]SE_arrayOfProduct;
		SE_arrayOfProduct = tempArray;
	}
	SE_arrayOfProduct[SE_logicAraayProduct] = newProdcut;
	SE_logicAraayProduct++;
}
//________________________________________________________________________________________________
void seller::SE_addConsumer(user* newConsumer)
{
	if (SE_logicOfArrayconsumers == SE_physicOfArrayConsumer)
	{
		SE_physicOfArrayConsumer *= 2;
		user **tempArray = new user*[SE_physicOfArrayConsumer];
		for (int i = 0; i < SE_logicOfArrayconsumers; i++)
			tempArray[i] = SE_arrayOfPurchaseConsumers[i];
		delete[] SE_arrayOfPurchaseConsumers;
		SE_arrayOfPurchaseConsumers = tempArray;
	}
	SE_arrayOfPurchaseConsumers[SE_logicOfArrayconsumers] = newConsumer;
	SE_logicOfArrayconsumers++;
}
//__________________________________________________________________________________________
void seller::SE_print()                                const// print his user name
{
	cout << U_UserName << endl;
}
//______________________________________________________________________________________________
void seller::SE_Addfeedback(const feedback& feed)
{
	if (SE_logicFeedbcak == SE_physicFeedback)
	{
		SE_physicFeedback *= 2;
		feedback * TempArray = new feedback[SE_physicFeedback];
		for (int i = 0; i < SE_logicFeedbcak; i++)
			TempArray[i] = SE_ArrayOfFeedbacks[i];
		delete[] SE_ArrayOfFeedbacks;
		SE_ArrayOfFeedbacks = TempArray;
	}
	SE_ArrayOfFeedbacks[SE_logicFeedbcak] = feed;
	SE_logicFeedbcak++;
}
//_____________________________________________________________________________________________
bool seller::SE_consumerIsInTheArray(const feedback& feed)
{
	for (int i = 0; i < SE_logicOfArrayconsumers; i++)
	{
		if (SE_arrayOfPurchaseConsumers[i] == feed.C_getConsumer())
			return true;
	}
	return false;
}


//____________________________________________________________________________________________________
const int & seller::SE_getLogicProduct()						const
{
	return SE_logicAraayProduct;
}
//________________________________________________________________________________________________
 product ** seller::SE_getArrayOfProduct()						const
{
	return SE_arrayOfProduct;
}
 //______________________________________________________________________________________
 void seller::SE_setLogic(int sizeOfP)
 {
	 SE_logicAraayProduct = sizeOfP;
 }
 //____________________________________________________________________________________________________
 bool seller::SE_isconsumerInTheArray(user* cons)
 {
	 for (int i = 0; i < SE_logicOfArrayconsumers; i++)
	 {
		 if (SE_arrayOfPurchaseConsumers[i] == cons)
			 return true;
	}
		 return false;
 }
 //______________________________________________________________________________
 bool seller::AS_findIfConsumerPurchase(user * ptr)
 {
	 for (int i = 0; i < SE_logicOfArrayconsumers; i++)
	 {
		 if (SE_arrayOfPurchaseConsumers[i] == ptr)//we compares the adresses between them
			 return true;
	 }
	 return false;
 }
 //___________________________________________________________________________________
 const int& seller::SE_getLogicfeedback()																const
 {
	 return SE_logicFeedbcak;
 }
 //______________________________________________________________________________________
 void seller::SE_printAllProduct()																		const
 {
	 for (int i = 0; i < SE_logicAraayProduct; i++)
		 cout << SE_arrayOfProduct[i] << endl;
 }
 void seller::print()																					const
 {
	 user::print();
 }