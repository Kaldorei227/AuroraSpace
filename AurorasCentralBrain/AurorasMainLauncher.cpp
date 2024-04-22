#include "AurorasMainLauncher.h"
#include "Aurora/Impl/AuroraCommunicatio.h"

namespace Aurora
{
	Aurora::AurorasMainLauncher::AurorasMainLauncher()
	{
		m_BaseAurorasObject = std::make_unique<Aurora::Impl::AuroraCommunication>();
	}

	AurorasMainLauncher::~AurorasMainLauncher()
	{
	}

	void AurorasMainLauncher::Launch()
	{
		m_BaseAurorasObject->Start();
	}
}