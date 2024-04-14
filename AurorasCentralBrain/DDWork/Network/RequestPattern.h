#pragma once
#include <iostream>
#include "Core/ZmqDD.h"

namespace Aurora::DDWork::Network
{
	class RequestPattern
	{
	public:
		RequestPattern(std::string adress);

		void SendMessage(std::string message);

		//TODO: Dopsat ping, dopsat methody ReceiveMess, EventuConnectionStateChange 

	private:
		std::unique_ptr<Core::ZmqDD> m_Server;
		std::atomic_bool m_NeedReceiveMessage;
	};
}