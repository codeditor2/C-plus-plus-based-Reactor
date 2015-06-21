#ifndef REACTOR_REACTOR_H_
#define REACTOR_REACTOR_H_

#include "eventHandler.h"
#include "RImplementation.h"

class ReactorImplementation;

namespace reactor
{

	class Reactor
	{
	public:
		Reactor();
		~Reactor();

		int RegisterHandler(EventHandler * handler, event_t evt);
		int RemoveHandler(EventHandler * handler);
		void HandleEvents(int timeout = 0);

	private:
		// ½ûÖ¹copy
		Reactor(const Reactor &);
		Reactor & operator=(const Reactor &);

	private:

		ReactorImplementation * m_reactor_impl;
	};

}
#endif
