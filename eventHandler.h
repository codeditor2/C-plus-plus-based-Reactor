#ifndef REACTOR_EVENTHANDLER_H_
#define REACTOR_EVENTHANDLER_H_

#define FD_SETSIZE 8192
#include <Winsock2.h>


namespace reactor
{
	// 事件类型
	typedef unsigned int event_t;
	enum
	{
		kReadEvent    = 0x01, ///< 读事件
		kWriteEvent   = 0x02, ///< 写事件
		kErrorEvent   = 0x04, ///< 出错事件
		kEventMask    = 0xff  ///< 事件掩码
	};

	// 句柄类型
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