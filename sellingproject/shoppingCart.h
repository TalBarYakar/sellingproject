#ifndef _SC_H
#define _SC_H
#include "consumer.h"
#include"order.h"
class shoppingCart
{
public:
	friend class appSystem;
	~shoppingCart();
	shoppingCart(const char *name,consumer* cons);
	//we are not releaseing the products or the productArray in that class becouse the order class will take care of it
	void S_setUserName(const char * name);
	void S_setProductArray();
	void S_setPrice();
	const char*S_getName()							const;
	const float& S_getPrice()						const;
	product** S_getProductArray()					const;
	void S_addproduct(product* newProduct);
	void S_shoppingCartPrint()						const;
	product* S_getproductByserialNumber(int serial)	;
	void removeProductFromCart(product** product,int size);
	
private:
	shoppingCart(const shoppingCart &other) = delete; // we dont want to have the possibility to copy shopping cart, and we hold shopping cart at consumer as pointer
	product** S_ProductArray;
	int S_logicSize,S_physicSize;
	float S_price;
	char S_consUserName[consumer::USER_NAME_LENGTH];
	order *S_order;
	consumer*S_consumer ;

};
#endif // !_SC_H

