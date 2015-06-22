#ifndef REACTOR_SELECTDEMULTIPLEXER_H_
#define REACTOR_SELECTDEMULTIPLEXER_H_

#include "eventDemultiplexer.h"

namespace reactor
{

	// ��selectʵ�ֵĶ�·�¼��ַ���
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
		fd_set              m_read_set;   ///< ���¼�fd����
		fd_set              m_write_set;  ///< д�¼�fd����
		fd_set              m_except_set; ///< �쳣�¼�fd����
		timeval             m_timeout;    ///< ��ʱ
	};
}

#endif 
