#include"consumerAndSeller.h"
consumerAndseller::consumerAndseller(char* userName, char*password, adress& ad) :user(userName, password, ad),consumer(ad,userName, password),seller(userName, password, ad)
{

}

void consumerAndseller::print()const
{
	user::print();
}