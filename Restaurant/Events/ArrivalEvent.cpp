#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"

ArrivalEvent::ArrivalEvent(int eTime, int oID, ORD_TYPE oType):Event(eTime, oID){
	OrdType = oType;
	OrderID=oID;
}



ArrivalEvent::ArrivalEvent(int eTime, int oID,int oSize, double oMoney, ORD_TYPE oType):Event(eTime, oID)
{
	OrdType = oType;
	OrderID=oID;
	OrdSize=oSize;
	OrdMoney=oMoney;
	//OrdDistance=Odistance;

}
ORD_TYPE ArrivalEvent::getOrdType(){
	return OrdType;
}
void ArrivalEvent::Execute(Restaurant* pRest)
{
	//This function should create an order and fills its data 
	// Then adds it to normal, vegan, or VIP order lists that you will create in phase1
	Order* pOrd = new Order(OrderID,OrdType);
	pOrd->SetID(OrderID);
	pOrd->Set_size(OrdSize);
	pOrd->setStatus(WAIT);
	pOrd->Set_ArrTime(EventTime);
	pOrd->Set_Money(OrdMoney);
	pOrd->SetDistance(OrdDistance);

	if (OrdType == TYPE_NRM)
		pRest->AddNormalToQueue(pOrd);
	else if (OrdType == TYPE_VGAN)
		pRest->AddToVeganQueue(pOrd);
	else if (OrdType == TYPE_VIP)
		pRest->AddToVIPArray(pOrd);
	
	
	///For the sake of demo, this function will just create an order and add it to DemoQueue
	///Remove the next code lines in phases 1&2
	//Order* pOrd = new Order(OrderID,OrdType);
	//pRest->AddtoDemoQueue(pOrd);
}
