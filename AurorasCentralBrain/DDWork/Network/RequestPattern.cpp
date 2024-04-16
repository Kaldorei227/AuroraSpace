#include "RequestPattern.h"

namespace DDWork::Network
{
	RequestPattern::RequestPattern(std::string adress) :
		m_NeedReceiveMessage{ false }
	{
		m_Server = std::make_unique<Core::ZmqDD>(adress, Core::PetternType::RequestPattern);
	}

	void RequestPattern::SendMessage(std::string message)
	{
		throw std::exception("RequestPattern::SendMessage isn't implemented");
	}
}