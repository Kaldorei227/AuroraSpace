#pragma once
#include "IResponsePattern.h"
#include "Core/ZmqDD.h"
#include "../Events/Event.h"
#include <thread>

namespace Aurora::DDWork::Network
{
	class ResponsePattern : public IResponsePattern
	{
	public:
		ResponsePattern(std::string adress);

		void SendString(std::string message) override;
		std::string ReceiveString() override;

		Events::IEvent<bool>& GetUserLogined() override;
	private:
		std::unique_ptr<Core::ZmqDD> m_Client;
		Events::Event<bool> m_UserLoginedEvent;

		std::jthread m_ReceivingThread;

		void ReceivingThread();
	};
}