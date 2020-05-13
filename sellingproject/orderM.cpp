#include"order.h"
#include"shoppingCart.h"
#include"seller.h"
order::order(shoppingCart  *ChossenshoppingCart)
{
	O_logic = 0;
	O_physic = 2;
	O_shoppingCart = ChossenshoppingCart;
	O_arrayOfChossenProduct = new product*[O_physic];
}
//______________________________________________________________________
order::~order()
{
	delete[] O_arrayOfChossenProduct;// we dont want to delete the products which the array contain
}
//_______________________________________________________________________________
void order::O_print()					const
{
	int i = 0;
	while (i < O_logic)
	{

		cout << O_arrayOfChossenProduct[i] << endl;
		i++;
	}
}

//_______________________________________________________________________________
void order::O_addItems(product* itemToPurchase) 
{
	if (O_logic == O_physic) 
	{
		O_physic *= 2;
		product **TempArray = new product*[O_physic];
		for (int i = 0; i < O_logic; i++) 
			TempArray[i] = O_arrayOfChossenProduct[i];
		delete[]O_arrayOfChossenProduct;
		O_arrayOfChossenProduct = TempArray;
	}
	O_finalPrice += itemToPurchase->P_getprice();
	O_arrayOfChossenProduct[O_logic] = itemToPurchase;
	O_logic++;
}
//_______________________________________________________________________________
void order::O_deleteProductFromSeller(consumer *cons)// after the purchase we eant to delete the product from the seller array 
{
	for (int i = 0; i < O_logic; i++)
	{
		seller* temp = O_arrayOfChossenProduct[i]->P_getSeller();
		if (temp->SE_isconsumerInTheArray(cons) == false)//if he already bought something from that seller
		{
			temp->SE_addConsumer(cons);
		}
		
			O_arrayOfChossenProduct[i]->P_productDeleteFromSelle(O_arrayOfChossenProduct[i]);// delete that roduct
	}
}
//___________________________________________________________________________________________________
const float& order::O_getPrice()										const									
{
	return O_finalPrice;
}
//_______________________________________________________________________________________________________
const	int& order::O_getLogic()										const
{
	return O_logic;
}
//_______________________________________________________________________________________________________
bool order::O_checkifProductAlreadyChoose(const int serial)				const// in case for selecting the same product more than once
{
	for (int i = 0; i < O_logic; i++)
	{
		if (O_arrayOfChossenProduct[i]->P_getSerialNumber() == serial)
			return true;
	}
	return false;
}
product** order::O_getArrayOfProduct()
{
	return O_arrayOfChossenProduct;
}