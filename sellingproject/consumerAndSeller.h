#ifndef _SAC_H
#define _SAC_H
#include"seller.h"
class consumerAndseller : public seller, public consumer
{
public:
	consumerAndseller(char* userName, char*password, adress& ad);
	virtual~consumerAndseller()
	{
		cout << "consumer and seller dis" << endl;
	}
	void print()const;
	
};
#endif // !_SAC_H
