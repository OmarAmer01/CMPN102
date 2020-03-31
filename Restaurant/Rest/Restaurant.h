#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Generic_DS\LinkedList.h"
#include "..\Generic_DS\priorityQueue.h"
#include "..\Events\Event.h"


#include "Order.h"

// it is the maestro of the project
class Restaurant  
{	
private:
	GUI *pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file

	
	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	Queue<Order*> DEMO_Queue;	//Important: This is just for demo
	/// ==>
	
	
	
	//
	// TODO: Add More Data Members As Needed
	//
	Queue<Order*> VEGANOrder;  //  vegan queues
	LinkedList<Order*>normalorder; //  vip linkedlist
	priorityQueue<Order*>VIPorder; // priority queue of vip
	Queue<Cook*>VIPcook;
	Queue<Cook*>NORMALcook;
	Queue<Cook*>VEGANcook;
	int TS;  //timestep
	int SV;     //speed of vip cook
	int SN;    //speed of normal cook
	int SG;   //speed of vegan cook
	int V;   // no. of vip cooks
	int N;  // no. of normal cooks
	int G;  // no. of vegan cooks
	int BO;  // the number of orders a cook must prepare before taking a break
	int BN;  //BREAK DURATION FOR NORMAL
	int BG;   //BREAK DURATION FOR VEGAN
	int BV;   //BREAK DURATION FOR VIP
	int AutoP;    //TIME TO PROMOT NORMAL ORDER TP VIP
	int M;

public:
	
	Restaurant();
	~Restaurant();
	
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();

	


	void FillDrawingList();

	//
	// TODO: Add More Member Functions As Needed
	void AddEvents(Event* ev); // add event to queue
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void AddToVeganQueue(Order* po); // add frozen to queue
	void AddNormalToList(Order* po); // add normal order to list
	void AddToVIPArray(Order* ord, double a);  //add to vip array
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ORD_TYPE Getordertype(char ordtype);   // convert the char to the order type
	void CancelNormal(int id);  // lsa mat3amlsh
/// ===================    DEMO-related functions. Should be removed in phases 1&2   ================= 

	void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
	void AddtoDemoQueue(Order* po);	//adds an order to the demo queue

/// ================================================================================================== 



};

#endif