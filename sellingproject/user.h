#ifndef _US_H
#define _US_H
#include"product.h"
#include"feedback.h"
class user 
{

public:
	static const int MINIMUMLENGTH = 6;
	static const int PASSWORD_LENGTH = 20;
	static const int USER_NAME_LENGTH = 20;
	user(const char*name, const char* password, const adress& a);
	virtual~user()
	{
	// we dont have any dynamic allocation we dont want to delete nothing
	}
	const adress& U_getAdress()																									const;
	const char* U_getName()																										const;
	const char* U_getPassword()																									const;
	void U_init(const adress& ad, const char*userName, const char*password);
	void U_setAdrees(const adress& ad);
	void U_setUsername(const char*userName);
	void U_setPassword(const char*password);
	bool U_checkValidity(const adress& ad, const char *userName, const char* password);// befor we will make new consumer we want to check that the input is valid
	virtual void  print()const = 0
	{
		U_Adress.A_adressPrint();
	}
	friend ostream& operator<<(ostream& os, const user* us) 
	{
		os << "user name: " << us->U_getName() << "   password *****" << "    adress   " << us->U_getAdress() << endl;// we dont want to reveal the user name password
		return os;
	}
protected:
	user(const user&other);
	char U_UserName[USER_NAME_LENGTH];
	char U_password[PASSWORD_LENGTH];
	adress U_Adress;
};
#endif // !_US_H
