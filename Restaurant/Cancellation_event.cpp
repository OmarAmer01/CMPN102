#include "Cancellation_event.h"
#include "../Restaurant/Rest/Restaurant.h"

Cancellation_event::Cancellation_event(int eventTime, int id):Event(eventTime, id)
{
}

void Cancellation_event::Execute(Restaurant* r)
{
	// excute el cancellation bta3 normal order
	r->CancelById(this->OrderID);
}

Cancellation_event::~Cancellation_event()
{
}

