#ifndef _FB_H
#define _FB_H
#pragma warning (disable:4996)
class consumer;
class feedback 
{
public:
	 const char* Eval[6]=  { "worst", "bad", "average", "nice","good","best" };//for the printing 
	static const int USER_NAME_LENGTH = 10;
	static const int DATE_LENGTH = 11;
	const enum F_evaluaton{worst, bad, average, nice,good,best};
	//~feedback() we dont need to write destructor becouse we dint use any dynamic allocation in that class    
	//we have an array of feedbacks , in order to allocate it we must give the feedbacks default values... we prefer not use the default constructor
	feedback(const char* date="notGiven" , const  consumer* cons=nullptr, const  F_evaluaton& evaluation=(F_evaluaton)2, const char* name="notgiven");
	void F_init(const char* date, const consumer* cons, const  F_evaluaton& evaluation,const char *sellerUserNmae);
	void F_setDate(const char *date);
	void F_setCosumer(const  consumer *consumer);
	void F_setEvaluation(const F_evaluaton& evaluation);
	bool F_checkValidity(const char* date,const  consumer* cons, const  F_evaluaton& evaluation,char *sellername)			const;
	void F_setUserName(const char*name);
	const consumer * C_getConsumer()	const;
	void print()						const ;
private:
const		consumer* F_cosumerWhoWrote;
		F_evaluaton F_discriptionOfEvaluation;
		char F_date[DATE_LENGTH];
	char F_consumerToFeedback[USER_NAME_LENGTH ];
};
#endif 