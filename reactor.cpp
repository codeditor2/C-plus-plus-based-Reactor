#include "reactor.h"
#include "RImplementation.h"


namespace reactor
{

	Reactor::Reactor()
	{	
		// 分配具体的实现类
		m_reactor_impl = new ReactorImplementation();
	}

	Reactor::~Reactor()
	{
		delete m_reactor_impl;
	}

	int Reactor::RegisterHandler(EventHandler * handler, event_t evt)
	{
		return m_reactor_impl->RegisterHandler(handler, evt);
	}


	int Reactor::RemoveHandler(EventHandler * handler)
	{
		return m_reactor_impl->RemoveHandler(handler);
	}


	void Reactor::HandleEvents(int timeout)
	{
		m_reactor_impl->HandleEvents(timeout);
	}

} 
