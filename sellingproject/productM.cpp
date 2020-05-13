#include"product.h"
#include"seller.h"
int product::serialNumber=1000;// that is static varible , every time the seller add new product the serial number will grew in 1
//__________________________________________________________________________________________________________________________________
bool product::P_checkValadity(const char*name,  const  P_type& kind, const float& price)
{
	if (strlen(name) > (MAX_LENGTH_PRODUCT_NAME - 1))
	{
	
		return false;
	}
	if (kind != kids && kind != electricity && kind != clothing && kind != office) 
	{
		return false;
	}
	if (price < 0)
	{
		cout << " --error --the price supposed to be graetter than 0" << endl;
		_sleep(2000);
		return false;
	}
	return true;// now we can be sure the input is valid , we can add product
}
//____________________________________________________________________________________________________________________________
void product::P_setName(const char *name) 
{
	strcpy(P_name, name);
}
//_______________________________________________________________________________________________________________________________

//_______________________________________________________________________________________________________________________________
void product::P_setP_type(const P_type& kind) 
{
	P_kindOfProduct = kind;
}
//_______________________________________________________________________________________________________________________________
product::product(const char*name,const  P_type& kind, const float& price, seller *ptr)//construcor 
{
	P_setName(name);
	P_setP_type(kind);
	P_setPrice(price);
	P_productOwnSeller = ptr;
	P_serialNUmber = ++serialNumber;
}

void product::P_setPrice(const float& price)
{
	P_price = price;
}
//__________________________________________________________________________________________________________________________________

//__________________________________________________________________________________________________________________________________
const float& product::P_getprice()							const
{
	return P_price;
}
//_____________________________________________________________________________________________________________________
const int& product::P_getSerialNumber()						const
{
	return P_serialNUmber;
}
//__________________________________________________________________________________________
const char* product::P_getname()							const
{
	return P_name;
}
//____________________________________________________________________________________________________
product::product(const product& other)// if we get the product we can assume is validity
{
	P_setName(other.P_name);
	P_setPrice(other.P_price);
	P_setP_type(other.P_kindOfProduct);
	P_serialNUmber =++serialNumber;
}
//______________________________________________________________________________________________________
void product::print()										const
{
	cout << "product name is:" << P_name << "  it price is:" << P_price << "$  it belongs to:" << P_typeStrings[P_kindOfProduct] << " section " << endl;
	cout<<"and his serialNumberis : " << P_serialNUmber<< endl;

}
//_______________________________________________________________________________________________________________
void product::P_productDeleteFromSelle(product* prod)// in case someone purchase the product we would like to delete it for the seller array
{
	int i = 0;
	int sizeOfArray = P_productOwnSeller->SE_getLogicProduct();
	product** Parray = P_productOwnSeller->SE_getArrayOfProduct();// we will have the arrayof product belonge to the seller which the product belong to 
	while (i < sizeOfArray && Parray[i] != prod) // as long as we havent reach to the product in the array
	{
		i++;
	}
	seller*temp = prod->P_getSeller();
	delete Parray[i];
	for (int j = i; j < (sizeOfArray ); j++)
	{
		Parray[j] = Parray[j + 1];
	}
	sizeOfArray--;
	temp->SE_setLogic(sizeOfArray);
}
//__________________________________________________________________________________
seller* product::P_getSeller()						const
{
	return P_productOwnSeller;
}
int product::P_getEval()							const		
{
	return P_kindOfProduct;
}