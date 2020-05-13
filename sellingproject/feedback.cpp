#include"feedback.h"
#include"consumerAndSeller.h"
#include<iostream>
#include<string.h>
using namespace std;

feedback::feedback(const char* date, const  consumer* cons, const  F_evaluaton& evaluation,const char* name)//consrtuctor
{
	F_init(date, cons, evaluation,name);
}
//_____________________________________________________________________________________________________________________________
void feedback::F_init(const char* date,const  consumer* cons,const  F_evaluaton& evaluation, const char* name)
{
	F_setCosumer(cons);
	F_setDate(date);
	F_setEvaluation(evaluation);
	F_setUserName(name);
}
//_____________________________________________________________________________________________________________________________
void feedback::F_setDate(const char *date)
{
	strcpy(F_date, date);
}
//_____________________________________________________________________________________________________________________________
void feedback::F_setCosumer( const consumer* consumer)
{
	F_cosumerWhoWrote = consumer;
}
//_____________________________________________________________________________________________________________________________
void feedback::F_setEvaluation( const F_evaluaton& evaluation)
{
	F_discriptionOfEvaluation = evaluation;
}
//_____________________________________________________________________________________________________________________________
void feedback::F_setUserName(const char*name)
{
	strcpy(F_consumerToFeedback, name);
}
//_____________________________________________________________________________________________________________________________
const consumer * feedback::C_getConsumer()										const
{
	return F_cosumerWhoWrote;
}
//_____________________________________________________________________________________________________________________________
void feedback::print()															const
{
	cout << "evaluation is   --" << Eval[F_discriptionOfEvaluation] << " --    date is:" << F_date << "    consumer user name:" << F_consumerToFeedback<< endl;
}

