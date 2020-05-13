#ifndef _PO_H
#define _PO_H
#include<iostream>
#include<string.h>
#include"Adress.h"
#pragma warning (disable:4996)
class seller;
using namespace std;
class product 
{
public:
	friend class seller;
	const char* P_typeStrings[4] = { "kids","office","electricity","clothing" };// for evaluation print 
	const enum P_type { kids, office, electricity, clothing };
	product(const char*name, const  P_type& kind, const float& price,  seller *ptr);//constructor
	~product() = default;// we dont have any dynamic allocation in that class , we dont need to write new destructor
	product(const product& other);//copy constructor
	static const int MAX_LENGTH_PRODUCT_NAME = 21;
	void P_setName(const char *name);
	void P_setP_type(const P_type& kind);
	void P_setPrice(const float& price);
	bool P_checkValadity(const char*name, const  P_type& kind, const float& price);// check if the input is valid , we will add product after we checked it .
	const float& P_getprice()							const;
	const int& P_getSerialNumber()						const;
	const char* P_getname()								const;
	void P_productDeleteFromSelle(product* prod);
	int P_getEval()										const;
	void print()										const;
	seller* P_getSeller()								const;
	friend ostream& operator<<(ostream& os, const product*  p) 
	{
		os << "product name: "<<p->P_getname()<<"     serial number  "<<p->P_getSerialNumber()<<"      price:   "<<p->P_getprice()<< endl;
		os <<"belong to section: "<< p->P_typeStrings[p->P_getEval()] << endl;
		return os;
	}
private :
	static int serialNumber;
	char  P_name[MAX_LENGTH_PRODUCT_NAME];
	int P_serialNUmber;
	P_type P_kindOfProduct;
	float P_price;
	seller* P_productOwnSeller;
};
#endif 

