#include "AuroraCommunicatio.h"
#include "../../DDWork/Network/ResponsePattern.h"
#include "SimpleLoginManager.h"

namespace Aurora::Impl
{
	AuroraCommunication::AuroraCommunication() 
		: BaseAurorasObject("AuroraCommunicatio")
	{
		m_LoginManager = std::make_unique<SimpleLoginManager>();
	}

	void AuroraCommunication::Start()
	{
		OpenCommBridge();
	}

	void AuroraCommunication::OpenCommBridge()
	{
		std::cout << "Opening connection";
		m_Client = std::make_unique<DDWork::Network::ResponsePattern>("tcp://*:5555", *m_LoginManager);
		auto number = 1;
		std::cin >> number;
	}
}