#ifndef __ORDER_H_
#define __ORDER_H_

#include "..\Defs.h"

class Order
{

protected:
	int ID;         //Each order has a unique ID (from 1 --> 999 )
	ORD_TYPE type;		//order type: Normal, vegan, VIP
	ORD_STATUS status;	//waiting, in-service, done
	int Distance;	//The distance (in meters) between the order location and the resturant 
	                
	double totalMoney;	//Total order money

	int ArrTime, ServTime, FinishTime;	//arrival, service start, and finish times
	
	
	//
	// TODO: Add More Data Members As Needed
	//
	int priority;
	int Order_Size;
	bool canceled;

public:
	Order(int ID, ORD_TYPE r_Type);
	virtual ~Order();

	void SetID(int id);
	int GetID();

	void Set_ORD_Type(ORD_TYPE Type);
	ORD_TYPE GetType() const;

	void SetDistance(int d);
	int GetDistance() const;

	void setStatus(ORD_STATUS s);
	ORD_STATUS getStatus() const;
	
	//
	// TODO: Add More Member Functions As Needed
	//

	void Set_Money(int money);
	int Get_money();

	void Set_ArrTime(int arrtime);
	int Get_Arrtime();

	void Set_serveTime(int servetime);
	int Get_servetime();

	void Set_finishTime(int finishtime);
	int Get_finishtime();
	
	// how to make setter and getter for status
	//waiting order
	int calc_priority();


	void Set_size(int s);
	int get_size();

	void cancel_order(bool s);
	bool is_canceled();

	void promotion(double extramoney);
};

#endif