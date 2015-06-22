#ifndef REACTOR_EVENT_DEMULTIPLEXER_H_
#define REACTOR_EVENT_DEMULTIPLEXER_H_

#include <set>
#include <map>

#include "eventHandler.h"
using namespace std;

namespace reactor
{

	class EventDemultiplexer
	{
	public:

		virtual ~EventDemultiplexer() {}

		virtual int WaitEvents(map<handle_t, EventHandler *> * handlers, int timeout = 0) = 0;

		virtual int RequestEvent(handle_t handle, event_t evt) = 0;

		virtual int UnrequestEvent(handle_t handle) = 0;
	};

}
#endif
