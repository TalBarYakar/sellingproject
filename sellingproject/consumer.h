#ifndef _CO_H
#define _CO_H
#include"user.h"
class shoppingCart;
class order;
class consumer :virtual public user
{
public:
	friend class appSystem;
	friend class feedback;
	virtual ~consumer();
	consumer(const adress& ad, const char *userName, const char* password);
	void s_printConsumerShoppingCart()																							const;
	void C_addProductToCart(product *newProduct);
	void printConsumerBelongeToShopping()																						const;
	const feedback& addFeedBack(const char* date, const  consumer* cons, const  feedback::F_evaluaton& evaluation, const char* name);
	void C_setOrder( );
	void C_setShoppingCart( );
	shoppingCart * C_getShoppingcart()																							const;	
	order * C_getOrder();
	virtual void print()const;
	bool operator<(const consumer* firstCons)	const;
protected:
	consumer(const consumer& other) = delete;// we dont want to have the possibility of copy consumers.
	shoppingCart *C_shoppingCart;// after making shoppingcart class iwill make the shopping cart into array and not pointer 
	order	*S_order;// we will convert order into regular varible and not a pointer
};
#endif // !_CO_H

