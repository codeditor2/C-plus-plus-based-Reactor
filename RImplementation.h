#ifndef REACTOR_IMPLEMENT_H_
#define REACTOR_IMPLEMENT_H_

#include "eventHandler.h"
#include "selectDemultiplexer.h"
using namespace std;

namespace reactor
{
	class ReactorImplementation
	{
	public:

		ReactorImplementation();
		~ReactorImplementation();

		int RegisterHandler(EventHandler * handler, event_t evt);
		int RemoveHandler(EventHandler * handler);
		void HandleEvents(int timeout);

	private:

		map<handle_t, EventHandler *>  m_handlers;
		EventDemultiplexer* m_demultiplexer;
	};
}
#endif