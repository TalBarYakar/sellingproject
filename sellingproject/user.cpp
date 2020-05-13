#include"user.h"

user::user(const char*userName, const char*password, const adress &ad)
{
	U_init(ad, userName, password);

}
bool user::U_checkValidity(const adress& ad, const char *userName, const char* password)
{
	if (strlen(userName) >(USER_NAME_LENGTH - 1) || strlen(password) > (PASSWORD_LENGTH - 1) ||(strlen(userName) < (MINIMUMLENGTH) || strlen(password)<(MINIMUMLENGTH)))
	{
		return false;
	}
	return true;
}
//____________________________________________________________________________________________________________________________
void user::U_init(const adress& ad, const char*userName, const char*password)
{
	U_setAdrees(ad);
	U_setPassword(password);
	U_setUsername(userName);
	

}
//______________________________________________________________________________________________________________________________
void user::U_setAdrees(const adress& ad)
{
	U_Adress.A_setCity(ad.A_getcity());
	U_Adress.A_setStreet(ad.A_getStreet());
	U_Adress.A_setHouseNumber(ad.A_getNumber());
}
//___________________________________________________________________________________________________________________
void user::U_setUsername(const char*userName)
{
	strcpy(U_UserName, userName);
}
//_____________________________________________________________________________________________________________________
void user::U_setPassword(const char*password)
{
	strcpy(U_password, password);
}
const adress& user::U_getAdress()																									const
{
	return U_Adress;
}
const char* user::U_getName()																										const
{
	return U_UserName;
}
const char* user::U_getPassword()																									const
{
	return U_password;
}
