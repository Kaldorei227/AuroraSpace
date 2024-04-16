#pragma once
#include <iostream>
#include <optional>
#include <zmq.h>
#include "PetternType.h"

namespace DDWork::Network::Core
{
	class ZmqDD
	{
	public:
		ZmqDD(std::string stringAddres, PetternType type);
		~ZmqDD();

		void ReleaseConnection();

		void SendFrame(std::string message, int flags);
		std::string ReceiveFrame(int flags);

		bool TrySendFrame(std::string message, int flags);
		std::optional<std::string> TryReceiveFrame(int flags);

	private:
		std::unique_ptr<void*> m_ZmqContext;
		std::unique_ptr<void*> m_ZmqSocket;
		std::atomic_bool m_NeedReceiveMessage;

		std::unique_ptr<void*> CreateSocketConnection(PetternType type);
		char* String2CharArray(std::string msg);
		std::string GetStringFromZmqMsg(zmq_msg_t msg);
	};
}