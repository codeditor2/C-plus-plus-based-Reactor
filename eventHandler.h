#ifndef REACTOR_EVENTHANDLER_H_
#define REACTOR_EVENTHANDLER_H_

#define FD_SETSIZE 8192
#include <Winsock2.h>


namespace reactor
{
	// �¼�����
	typedef unsigned int event_t;
	enum
	{
		kReadEvent    = 0x01, ///< ���¼�
		kWriteEvent   = 0x02, ///< д�¼�
		kErrorEvent   = 0x04, ///< �����¼�
		kEventMask    = 0xff  ///< �¼�����
	};

	// �������
	typedef ::SOCKET handle_t;

	class EventHandler
	{
	public:

		virtual handle_t GetHandle() const = 0;

		virtual void HandleRead() {}

		virtual void HandleWrite() {}

		virtual void HandleError() {}

	protected:

		EventHandler() {}
		virtual ~EventHandler() {}
	};
}
#endif