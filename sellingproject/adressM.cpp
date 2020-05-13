#include"product.h"
bool adress::A_checkValidity(const char*city, const char*street, const int&  houseNumber)// we will make pointer to adress if the validation test will be true we will dynamicly allocated memory for it 
{
	if (strlen(city) > (MAX_LENGTH_CITY_STREET) || strlen(street) > MAX_LENGTH_CITY_STREET)
		return false;
	return true;
}
//__________________________________________________________________________________________________________________
void adress::A_initAdress(const char*city, const char*street, const int&  houseNumber)
{
	A_setCity(city);
	A_setStreet(street);
	A_setHouseNumber(houseNumber);
}
//__________________________________________________________________________________________________________________
void adress::A_setCity(const char *city)
{
	strcpy(A_city, city);
}
//__________________________________________________________________________________________________________________
void adress::A_setStreet(const char *street)
{
	strcpy(A_street, street);
}
//__________________________________________________________________________________________________________________
void adress::A_setHouseNumber(const int& num)
{
	A_houseNUmber = num;
}
//__________________________________________________________________________________________________________________
adress::adress(const char*city, const char*street, const int&  houseNumber)
{
	A_initAdress(city, street, houseNumber);
}
//___________________________________________________________________________________________________________________
void adress::A_adressPrint()						const
{
	cout << A_city << "     " << A_street << "    " << A_houseNUmber << endl;
}
//_______________________________________________________________________________________________________________
adress::adress(const adress& other)//copy constructor
{
	strcpy(A_city, other.A_city);
	strcpy(A_street, other.A_street);
	A_houseNUmber = other.A_houseNUmber;
}
//______________________________________________________________________________________________________________
const char*  adress::A_getcity()						const
{
	return A_city;
}
//______________________________________________________________________________________________________________
const char*  adress::A_getStreet()					const
{
	return A_street;
}
//______________________________________________________________________________________________________________
const int& adress::A_getNumber()					const
{
	return A_houseNUmber;
}
//______________________________________________________________________________________________________________
