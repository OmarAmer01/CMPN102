#pragma once
#include "Events\Event.h"
class PromotionEvent :
	public Event
{
	double MoneyPaid;

public:
	PromotionEvent(int eventTime, int ID,double m);
	virtual void Execute(Restaurant* r);  // lsa da mat3amlsh 
	virtual ~PromotionEvent();
	double GetMoneyPaid();
};

