#include"consumer.h"
#include "shoppingCart.h"
#include"feedback.h"
consumer::~consumer()
{
	delete C_shoppingCart;
	if (S_order != nullptr)
		delete S_order;
}
//______________________________________________________________________________________________________________________

void consumer::s_printConsumerShoppingCart()				const
{
	C_shoppingCart->S_shoppingCartPrint();
}
//__________________________________________________________________________________________________________
consumer::consumer(const adress& ad, const char *userName, const char* password):user(userName,password,ad)
{
	S_order = nullptr;//we will allocate the needed memory after the consumer will enter the order opption
	C_setShoppingCart();
}
//_____________________________________________________________________________________________________________________________
void consumer::C_addProductToCart(product *newProduct)
{
	C_shoppingCart->S_addproduct(newProduct);
}
//________________________________________________________________________________________________________________________________________
void consumer::printConsumerBelongeToShopping()           const
{
	cout << U_password<<"     " << U_UserName << endl;
	U_Adress.A_adressPrint();
}
//_____________________________________________________________________________________________________________________________
const feedback& consumer::addFeedBack(const char* date, const  consumer* cons, const  feedback::F_evaluaton& evaluation, const char* name)
{
	feedback newFeedback(date, cons, evaluation, name);
	return newFeedback;
}

//__________________________________________________________________________________________________________
shoppingCart * consumer::C_getShoppingcart()											const
{
	return C_shoppingCart;
}
//_____________________________________________________________________________________________________________________________
order * consumer::C_getOrder()
{
	return S_order;
}
//_____________________________________________________________________________________________________________________________
void consumer::C_setOrder( )
{
	S_order = new order(C_shoppingCart);
}
//______________________________________________________________________________________________________________________________
void consumer::C_setShoppingCart()
{
	C_shoppingCart = new shoppingCart(U_UserName, this);
}
void consumer::print()const
{
	user::print();
}
bool consumer::operator<(const consumer* otherCons)												const
{
	return((this->C_shoppingCart->S_getPrice()) < (otherCons->C_shoppingCart->S_getPrice()));
}
