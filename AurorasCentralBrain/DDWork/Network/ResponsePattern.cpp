#include "ResponsePattern.h"

namespace Aurora::DDWork::Network
{
	ResponsePattern::ResponsePattern(std::string adress)
	{
		m_Client = std::make_unique<Core::ZmqDD>(adress, Core::PetternType::ResponsePattern);
		m_ReceivingThread = std::jthread([&] 
			{
				ReceivingThread();
			});
	}

	void ResponsePattern::SendString(std::string message)
	{
		m_Client->SendFrame(message, 0);
	}

	std::string ResponsePattern::ReceiveString()
	{
		return m_Client->ReceiveFrame(0);
	}

	Events::IEvent<bool>& ResponsePattern::GetUserLogined()
	{
		return m_UserLoginedEvent;
	}

	void ResponsePattern::ReceivingThread()
	{

	}
}