#include <errno.h>
#include <assert.h>
#include <vector>
#include "selectDemultiplexer.h"


namespace reactor
{
	#pragma comment(lib, "Ws2_32.lib")

	SelectDemultiplexer::SelectDemultiplexer()
	{
		this->Clear();
	}

	int SelectDemultiplexer::WaitEvents(
			std::map<handle_t, EventHandler *> * handlers,
			int timeout)
	{
		// 用select获取发生事件的fd集合
		m_timeout.tv_sec = timeout / 1000;
		m_timeout.tv_usec = timeout % 1000 * 1000;
		int max_fd = handlers->rbegin()->first;
		int ret = select(max_fd + 1, &m_read_set, &m_write_set,
						 &m_except_set, &m_timeout);
		if (ret <= 0)
		{
			return ret;
		}
		// 转化select的结果
		std::map<handle_t, EventHandler *>::iterator it = handlers->begin();
		while (it != handlers->end())
		{
			if (FD_ISSET(it->first, &m_except_set))
			{
				it->second->HandleError();
				FD_CLR(it->first, &m_read_set);
				FD_CLR(it->first, &m_write_set);
			}
			else
			{
				if (FD_ISSET(it->first, &m_read_set))
				{
					it->second->HandleRead();
					FD_CLR(it->first, &m_read_set);
				}
				if (FD_ISSET(it->first, &m_write_set))
				{
					it->second->HandleWrite();
					FD_CLR(it->first, &m_write_set);
				}
			}
			FD_CLR(it->first, &m_except_set);
			++it;
		}
		return ret;
	}

	int SelectDemultiplexer::RequestEvent(handle_t handle, event_t evt)
	{
		if (evt & kReadEvent)
		{
			FD_SET(handle, &m_read_set);
		}
		if (evt & kWriteEvent)
		{
			FD_SET(handle, &m_write_set);
		}
		FD_SET(handle, &m_except_set);
		return 0;
	}

	int SelectDemultiplexer::UnrequestEvent(handle_t handle)
	{
		FD_CLR(handle, &m_read_set);
		FD_CLR(handle, &m_write_set);
		FD_CLR(handle, &m_except_set);
		return 0;
	}

	void SelectDemultiplexer::Clear()
	{
		FD_ZERO(&m_read_set);
		FD_ZERO(&m_write_set);
		FD_ZERO(&m_except_set);
	}
}
