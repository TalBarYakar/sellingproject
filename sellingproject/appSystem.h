#ifndef _AS_H
#define _AS_H
#include"consumerAndSeller.h"
class appSystem 
{
public:
	static const int MAXSIZEINPUT = 80;
	appSystem();
	~appSystem();
	void AS_updateArrays();
	void AS_addUser(user *ptr);
	user *AS_createNewUser(int i);
	void AS_display();
	void AS_displayForConsumer();
	user* returnExistUser(const char*name, const char*password)const;
	void AS_displayForSeller();
	void AS_cosumerMenu(consumer *cons);
	void AS_consumerAndSellerMenue();
	void AS_printAllProduct()											const;
	bool AS_printProductSpecificName(char *name)						const;
	void AS_printShoppingCart()											const;
 	product*   AS_getProductBySerialNumber(int serial)					const;
	bool AS_printAllSellerUserName()									const;
	user* AS_findSellerForFeedback(char *name)							const;
	void AS_printAllConsumer()				const;
	feedback AS_getFeedback(consumer *cons);
	bool AS_existUser(char*name)										const;
	void AS_menuForSeller(seller *currSeller);
	void AS_OrderMenuForConsumer(consumer *consumer);
	bool AS_checlValidityOfDate(char *date);
	void operatorCheck();
	consumer* returnConsumerByUserName(const char*name)					const;
	void deleteFromShoppingCurt(product* arrayOfProducts,int &size);
	const user* operator+=(user*newuser);
	void AS_printConsumerAndSellerUsers()								const;
	
private:
	user** AS_arrayOfUsers;
	int AS_logic, AS_physic;

};
#endif // !_AS_H
