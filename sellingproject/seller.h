#ifndef _SE_H
#define _SE_H
#include"consumer.h"
class feedback;
class seller:virtual public user
{
public:
	friend class appSystem;
	virtual ~seller();
	seller(const char *SE_userName,const char *SE_password, const adress &a);
	void SE_setArrays();
	void SE_addProduct( product* newProdcut);
	void SE_addConsumer(user* consumer);
	void SE_print()																					const;
	void  SE_Addfeedback(const feedback& feed);
	bool  SE_consumerIsInTheArray(const feedback& feed);
	 //void AS_sellerMenu();
	 const int & SE_getLogicProduct()																const;
	 product	** SE_getArrayOfProduct()															const;
	 void SE_setLogic(int sizeOfP);
	 bool SE_isconsumerInTheArray(user* cons);
	 bool AS_findIfConsumerPurchase(user * ptr);
	 const int& SE_getLogicfeedback()																const;
	 void SE_printAllProduct()																		const;
	virtual void print()																					const;
private:
	feedback *SE_ArrayOfFeedbacks;
	int SE_logicFeedbcak, SE_physicFeedback;
	product** SE_arrayOfProduct;
	int SE_logicAraayProduct, SE_physicArrayProduct;
	user ** SE_arrayOfPurchaseConsumers;
	int SE_logicOfArrayconsumers, SE_physicOfArrayConsumer;
};
#endif // !_SE_H
