#ifndef REACTOR_SELECTDEMULTIPLEXER_H_
#define REACTOR_SELECTDEMULTIPLEXER_H_

#include "eventDemultiplexer.h"

namespace reactor
{

	// 由select实现的多路事件分发器
	class SelectDemultiplexer : public EventDemultiplexer
	{
	public:
		SelectDemultiplexer();

		virtual int WaitEvents(std::map<handle_t, EventHandler *> * handlers,
							   int timeout = 0);

		virtual int RequestEvent(handle_t handle, event_t evt);

		virtual int UnrequestEvent(handle_t handle);

	private:
		void Clear();

	private:
		fd_set              m_read_set;   ///< 读事件fd集合
		fd_set              m_write_set;  ///< 写事件fd集合
		fd_set              m_except_set; ///< 异常事件fd集合
		timeval             m_timeout;    ///< 超时
	};
}

#endif 
