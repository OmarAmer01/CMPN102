#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

#include "Restaurant.h"




Restaurant::Restaurant() 
{
	pGUI = NULL;
}

void Restaurant::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();
	
		LoadFile();
		
		int x=1; // a variable to know after 5 time steps
	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
				for(int i=0;i<20;i++){
			while(EventsQueue.getPtrToFront()->getItem()->getEventTime()==i){//while the event time=the current time step
				ArrivalEvent *p=dynamic_cast<ArrivalEvent*>(EventsQueue.getPtrToFront()->getItem());
				if(p){    //if it is an arrival event
					p->Execute(this); //generate an order and add it to the appropriate waiting list
				}else if((Cancellation_event*)EventsQueue.getPtrToFront()->getItem()){    //if it is a cancellation event
					if(!(normalorder.isEmpty())){
						                                // delete the corresponding normal order if found
                    
				}
				}
				Event *u=EventsQueue.getPtrToFront()->getItem();
				EventsQueue.dequeue(u);// get the next event
			}
			Order *Q=VIPorder.getPtrToFront()->getItem();
			VIPorder.dequeue(Q);                            //each time step pick one order from each type and add it to inservice list
			Inservicelist.InsertEnd(Q);                            // i used inserend so that in finished list the first order is the first order putted in inservice list

			Order *t=VEGANOrder.getPtrToFront()->getItem();
			VEGANOrder.dequeue(t);
			Inservicelist.InsertEnd(t);

			Order *w=normalorder.getPtrToFront()->getItem();
			normalorder.dequeue(w);
			Inservicelist.InsertEnd(w);
			if(i==(5*x)){ //each 5 time steps pick one order from each type from inservice list to finished list
				Order*e=Inservicelist.getHead()->getItem(); //the first order putted in inservice list which is a vip order
				Finishedlist.InsertEnd(e);
				Inservicelist.DeleteFirst(); //pick this order from in service list
				 //put it in finished list

		        Order*a=Inservicelist.getHead()->getItem();
				Finishedlist.InsertEnd(a);
				Inservicelist.DeleteFirst();
				

				Order*b=Inservicelist.getHead()->getItem();
				Finishedlist.InsertEnd(b);
				Inservicelist.DeleteFirst();
				

				x++; //so that we enter the if second time after 5 time steps when i = 5*x=5*2=10 and so on
			}
		pGUI->PrintMessage("click to display the output of next time step");
			pGUI->waitForClick();
			this->FillDrawingList();
		
				pGUI->UpdateInterface();
		}
		
		break;
	case MODE_STEP:
		break;
	case MODE_SLNT:
		break;
	case MODE_DEMO:
		Just_A_Demo();

	};

}



//////////////////////////////////  Event handling functions   /////////////////////////////

//Executes ALL events that should take place at current timestep
void Restaurant::ExecuteEvents(int CurrentTimeStep)
{
	Event *pE;
	while( EventsQueue.peekFront(pE) )	//as long as there are more events
	{
		if(pE->getEventTime() > CurrentTimeStep )	//no more events at current timestep
			return;

		pE->Execute(this);
		EventsQueue.dequeue(pE);	//remove event from the queue
		delete pE;		//deallocate event object from memory
	}

}


Restaurant::~Restaurant()
{
		if (pGUI)
			delete pGUI;
}

void Restaurant::FillDrawingList()
{
	int v=0;// to count the number of waiting  vip orders
		int ve=0;// to count the number of waiting  vegan orders
		int n=0;// to count the number of waiting  normal orders
			while(!(VIPorder.isEmpty())){// this 4 while loops to add all orders to the drawing list
				pGUI->AddToDrawingList(VIPorder.getPtrToFront()->getItem());
				Order *r=VIPorder.getPtrToFront()->getItem();
				VIPorder.dequeue(r);
				v++;
			}
			while(!(VEGANOrder.isEmpty())){
				pGUI->AddToDrawingList(VEGANOrder.getPtrToFront()->getItem());
				Order *r=VEGANOrder.getPtrToFront()->getItem();
				VEGANOrder.dequeue(r);
				ve++;
			}
				while(!(normalorder.isEmpty())){
				pGUI->AddToDrawingList(normalorder.getPtrToFront()->getItem());
				Order *r=normalorder.getPtrToFront()->getItem();
				normalorder.dequeue(r);
				n++;
			}
				while(Inservicelist.DeleteNode(Inservicelist.getHead()->getItem())){
					Inservicelist.getHead()->getItem()->setStatus(SRV);
					pGUI->AddToDrawingList(Inservicelist.getHead()->getItem());
				}
					while(Finishedlist.DeleteNode(Finishedlist.getHead()->getItem())){
					Finishedlist.getHead()->getItem()->setStatus(DONE);
					pGUI->AddToDrawingList(Finishedlist.getHead()->getItem());
				}

				//This function should be implemented in phase1
	//It should add ALL orders and Cooks to the drawing list
	//It should get orders from orders lists/queues/stacks/whatever (same for Cooks)
	//To add orders it should call function  void GUI::AddToDrawingList(Order* pOrd);
	//To add Cooks it should call function  void GUI::AddToDrawingList(Cook* pCc);
	
}




//////////////////////////////////////////////////////////////////////////////////////////////
/// ==> 
///  DEMO-related functions. Should be removed in phases 1&2

//Begin of DEMO-related functions



void Restaurant::AddEvents(Event* ev)
{
	EventsQueue.enqueue(ev);
}

void Restaurant::AddToVeganQueue(Order* po)
{
	VEGANOrder.enqueue(po);
}

void Restaurant::AddNormalToQueue(Order* po)
{
	normalorder.enqueue(po);
}

void Restaurant::AddToVIPArray(Order* ord)
{
	VIPorder.enqueue(ord,ord->GetPriority());
}

ORD_TYPE Restaurant::Getordertype(char ordtype)
{
	if (ordtype == 'V')
		return TYPE_VIP;
	else if (ordtype == 'N')
		return TYPE_NRM;
	else if (ordtype == 'G')
		return TYPE_VGAN;
	
}

void Restaurant::CancelNormal(int id)
{
	// lsa cancel of order 
}

//This is just a demo function for project introductory phase
//It should be removed starting phase 1
void Restaurant::Just_A_Demo()
{
	
	//
	// THIS IS JUST A DEMO FUNCTION
	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
	
	int EventCnt;	
	Order* pOrd;
	Event* pEv;
	srand(time(NULL));

	pGUI->PrintMessage("Just a Demo. Enter EVENTS Count(next phases should read I/P filename):");
	EventCnt = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer

	pGUI->PrintMessage("Generating Events randomly... In next phases, Events should be loaded from a file...CLICK to continue");
	pGUI->waitForClick();
		
	//Just for sake of demo, generate some cooks and add them to the drawing list
	//In next phases, Cooks info should be loaded from input file
	int C_count = 12;	
	Cook *pC = new Cook[C_count];
	int cID = 1;

	for(int i=0; i<C_count; i++)
	{
		cID+= (rand()%15+1);	
		pC[i].setID(cID);
		pC[i].setType((ORD_TYPE)(rand()%TYPE_CNT));
	}	

		
	int EvTime = 0;

	int O_id = 1;
	
	//Create Random events and fill them into EventsQueue
	//All generated event will be "ArrivalEvents" for the demo
	for(int i=0; i<EventCnt; i++)
	{
		O_id += (rand()%4+1);		
		int OType = rand()%TYPE_CNT;	//Randomize order type		
		EvTime += (rand()%5+1);			//Randomize event time
		pEv = new ArrivalEvent(EvTime,O_id,(ORD_TYPE)OType);
		EventsQueue.enqueue(pEv);

	}	

	// --->   In next phases, no random generation is done
	// --->       EventsQueue should be filled from actual events loaded from input file

	
	
	
	
	//Now We have filled EventsQueue (randomly)
	int CurrentTimeStep = 1;
	

	//as long as events queue is not empty yet
	while(!EventsQueue.isEmpty())
	{
		//print current timestep
		char timestep[10];
		itoa(CurrentTimeStep,timestep,10);	
		pGUI->PrintMessage(timestep);


		//The next line may add new orders to the DEMO_Queue
		ExecuteEvents(CurrentTimeStep);	//execute all events at current time step
		

/////////////////////////////////////////////////////////////////////////////////////////
		/// The next code section should be done through function "FillDrawingList()" once you
		/// decide the appropriate list type for Orders and Cooks
		
		//Let's add ALL randomly generated Cooks to GUI::DrawingList
		for(int i=0; i<C_count; i++)
			pGUI->AddToDrawingList(&pC[i]);
		
		//Let's add ALL randomly generated Ordes to GUI::DrawingList
		int size = 0;
		Order** Demo_Orders_Array = DEMO_Queue.toArray(size);
		
		for(int i=0; i<size; i++)
		{
			pOrd = Demo_Orders_Array[i];
			pGUI->AddToDrawingList(pOrd);
		}
/////////////////////////////////////////////////////////////////////////////////////////

		pGUI->UpdateInterface();
		Sleep(1000);
		CurrentTimeStep++;	//advance timestep
		pGUI->ResetDrawingList();
	}

	delete []pC;


	pGUI->PrintMessage("generation done, click to END program");
	pGUI->waitForClick();

	
}
////////////////

void Restaurant::AddtoDemoQueue(Order *pOrd)
{
	DEMO_Queue.enqueue(pOrd);
}

/// ==> end of DEMO-related function
//////////////////////////////////////////////////////////////////////////////////////////////

//By OmarAbdelGhani

void Restaurant::LoadFile(){
	ifstream IF("input.txt",ios::in);

	IF>>N; //initialize No. of Normal cooks
	IF>>G; // Same for vegan
	IF>>V; // and for VIP

	IF>>SN; //Initialize speed of Normal Cooks
	IF>>SG; // for Vegan Cooks
	IF>>SV; //for VIP

	IF>>BO; //Initialize No. of orders before break
	IF>>BN; //Break duration for Normal cooks
	IF>>BG; // for vegan
	IF>>BV; // for VIP


	IF>>AutoP; //Initialize NO. of time steps befor auto promotion

	IF>>M; //Initialize No. of events

	//Looping until i=m to initialize all events
	char Etype; // for the type of event
	int eTime; //time of arrival
	int Id;   //Id of Order
	char Otype; //type of order
	ORD_TYPE T; //type of order in enum format
	int Size; // Size of Order
	double Money; // total money of order
	for (int i=0;i<M;i++){
		IF>>Etype;

		if (Etype=='R'){
			IF>>Otype;
			T=Getordertype(Otype);
			IF>>eTime;
			IF>>Id;
			IF>>Size;
			IF>>Money;
			ArrivalEvent *R=new ArrivalEvent(eTime,Id,Size,Money,T);

		}
		else if (Etype=='X'){
			IF>>eTime;
			IF>>Id;
			Cancellation_event * X=new Cancellation_event(eTime,Id);

		}
		else if (Etype=='P'){



		}


	}



}
