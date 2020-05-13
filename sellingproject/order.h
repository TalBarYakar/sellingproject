#ifndef _OR_H
#define _OR_H
class consumer;
class shoppingCart;
class product;
class order 
{
public:
	order(shoppingCart  *ChossenshoppingCart);
	~order();
	 void O_print()														const;
	void O_addItems(product* itemToPurchase);
	void O_deleteProductFromSeller(consumer *cons );
	const float& O_getPrice()											const;                      
	const int& O_getLogic()												const;
	bool O_checkifProductAlreadyChoose(const int serial)				const;
	product** O_getArrayOfProduct();
private:
	order(const  order & other) = delete;// we dont want to have the opption to copy an order
	product** O_arrayOfChossenProduct;
	float O_finalPrice;
	shoppingCart* O_shoppingCart;
	int O_logic, O_physic;

	

};
#endif 
