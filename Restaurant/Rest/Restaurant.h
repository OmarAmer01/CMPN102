#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Generic_DS\LinkedList.h"
#include "..\Generic_DS\priorityQueue.h"
#include "..\Events\Event.h"
#include "..\Events\ArrivalEvent.h"
#include "..\Cancellation_event.h"
#include "..\PromotionEvent.h"
#include <fstream>



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
	Queue<Order*>normalorder; //  vip linkedlist
	priorityQueue<Order*>VIPorder; // priority queue of vip
	LinkedList<Cook*>VIPcook;
	LinkedList<Cook*>NORMALcook;
	LinkedList<Cook*>VEGANcook;
	LinkedList<Order*>Inservicelist;
	LinkedList<Order*>Finishedlist;
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
	void AddNormalToQueue(Order* po); // add normal order to list
	void AddToVIPArray(Order* ord);  //add to vip array   //Omar AbdelGhani removed the priorty as it is by default in the order
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ORD_TYPE Getordertype(char ordtype);   // convert the char to the order type
	void CancelNormal(int id);  // lsa mat3amlsh
/// ===================    DEMO-related functions. Should be removed in phases 1&2   ================= 

	void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
	void AddtoDemoQueue(Order* po);	//adds an order to the demo queue

/// ================================================================================================== 
	
	//By Omar AbdelGhani
	void LoadFile();


};

#endif