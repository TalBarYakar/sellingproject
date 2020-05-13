#include"shoppingCart.h"
shoppingCart::shoppingCart(const char* name,consumer *cons)
{
	S_setProductArray();
	S_setUserName(name);
	S_setPrice();
	S_consumer = cons;
	S_order=new order(this);
}
//________________________________________________________________
shoppingCart::~shoppingCart()
{
	delete S_order;
	// we dont want to delete the product belong to that array becouse they are belong to a seller, when the seller will die they will delete
	delete[] S_ProductArray;
	S_consumer = nullptr;// in order to avoid an enfinity loop
}
//_________________________________________________________________
void shoppingCart::S_setUserName(const char * name)
{
	strcpy(S_consUserName, name);
}
//_________________________________________________________________
void shoppingCart::S_setProductArray()
{
	S_logicSize = 0;
	S_physicSize = 2;
	S_ProductArray = new product*[S_physicSize];
}
//_________________________________________________________________
void shoppingCart::S_setPrice()
{
	S_price = 0;
}
//_________________________________________________________________
const char* shoppingCart::S_getName()							const
{
	return S_consUserName;
}
//_________________________________________________________________
const float& shoppingCart::S_getPrice()							const
{
	return S_price;
}
//_________________________________________________________________
 product** shoppingCart::S_getProductArray()					const
{
	return S_ProductArray;
}
//_________________________________________________________________
void shoppingCart::S_addproduct(product* newProduct)
{
	if (S_logicSize == S_physicSize)
	{
		S_physicSize *= 2;
		product** TempProductArray = new product*[S_physicSize];
		for (int i = 0; i < S_logicSize; i++)
			TempProductArray[i] = S_ProductArray[i];
		delete[] S_ProductArray;
		S_ProductArray = TempProductArray;
		
	}

	S_price += newProduct->P_getprice();
	
	S_ProductArray[S_logicSize] = newProduct;
	S_logicSize++;
}
//_______________________________________________________________________________________________________
void shoppingCart::S_shoppingCartPrint()					const
{
	for (int i = 0; i < S_logicSize; i++)
	{
		cout <<S_ProductArray[i]<<endl;

	}
}
//_____________________________________________________________________________________________________
product* shoppingCart::S_getproductByserialNumber(int serial)		
{
	int i = 0;
	while (i < S_logicSize)
	{
		
		if (S_ProductArray[i]->P_getSerialNumber() == serial)
			return S_ProductArray[i];
		i++;
	}
	return nullptr;
}
void shoppingCart::removeProductFromCart(product **product, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < S_logicSize; j++)
		{
			if (S_ProductArray[j] == product[i])
			{
				S_logicSize--;
				for (int k = j; k < S_logicSize; k++)
				{
					S_ProductArray[k] = S_ProductArray[k + 1];
				}
			}
		}
	}
}