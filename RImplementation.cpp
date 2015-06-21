#include "RImplementation.h"

namespace reactor
{

	ReactorImplementation::ReactorImplementation()
	{
		m_demultiplexer = new SelectDemultiplexer();
	}


	ReactorImplementation::~ReactorImplementation()
	{
		delete m_demultiplexer;
	}

	int ReactorImplementation::RegisterHandler(EventHandler * handler, event_t evt)
	{
		handle_t handle = handler->GetHandle();
		std::map<handle_t, EventHandler *>::iterator it = m_handlers.find(handle);
		if (it == m_handlers.end())
		{
			m_handlers[handle] = handler;
		} 
		return m_demultiplexer->RequestEvent(handle, evt);
	}

	int ReactorImplementation::RemoveHandler(EventHandler * handler)
	{
		handle_t handle = handler->GetHandle();
		m_handlers.erase(handle);
		return m_demultiplexer->UnrequestEvent(handle);
	}

	void ReactorImplementation::HandleEvents(int timeout)
	{
		m_demultiplexer->WaitEvents(&m_handlers);
	}

}