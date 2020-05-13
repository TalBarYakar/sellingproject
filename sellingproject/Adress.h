#ifndef _AD_H
#define _AD_H 
#include<iostream>
#include<string.h>
using namespace std;
class adress
{
public :
	friend class user;
	adress() = default;
	//~adress() is not needed becouse we dont have any dynamic allocation int that class
	adress(const char*city, const char*street, const int&  houseNumber);// constructor 
	adress(const adress& other);//copy constructor
	static const int MAX_LENGTH_CITY_STREET = 26;
	bool A_checkValidity(const char*city, const char*street,const int&  houseNumber);// check if the input is valid
	void A_initAdress(const char*city, const char*street, const int&  houseNumber);
	void A_setCity(const char *city);
	void A_setStreet(const char *street);
	void A_setHouseNumber(const int& num);
	void A_adressPrint()						const;
	const char* A_getcity()						const;
	const char* A_getStreet()					const;
	const int& A_getNumber()					const;
	friend ostream& operator<<(ostream& os, const adress& ad)
	{
		os << "city:    " << ad.A_getcity() << "   street:" << ad.A_getStreet() << "  house number" << ad.A_getNumber() << endl;
		return os;
	}
private:
	char A_city[MAX_LENGTH_CITY_STREET];
	char A_street[MAX_LENGTH_CITY_STREET];
	int A_houseNUmber;
};

	

#endif 

