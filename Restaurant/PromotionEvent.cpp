#include "PromotionEvent.h"
#include "../Restaurant/Rest/Restaurant.h"

PromotionEvent::PromotionEvent(int eventTime, int ID,double m):Event(eventTime,ID){
	MoneyPaid=m;
}
	 void PromotionEvent::Execute(Restaurant* r){
		Order O= r->CancelById(OrderID);
		 r->AddToVIPArray(&O);
	}

PromotionEvent::~PromotionEvent(void)
{
}
double PromotionEvent::GetMoneyPaid(){
	return MoneyPaid;
}