#pragma once
#include"Events/Event.h"
#include"Rest/Restaurant.h"

class Cancellation_event:public Event
{

public:
	Cancellation_event(int eventTime, int ID);
	// lsse el excute
};

