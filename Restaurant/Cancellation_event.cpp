#include "Cancellation_event.h"

Cancellation_event::Cancellation_event(int eventTime, int id):Event(eventTime, id)
{
}

void Cancellation_event::Execute(Restaurant* r)
{
	// excute el cancellation bta3 normal order
}

Cancellation_event::~Cancellation_event()
{
}

