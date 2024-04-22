#include "SimpleLoginManager.h"

namespace Aurora::Impl
{
	SimpleLoginManager::SimpleLoginManager()
		: m_Username("Kaldorei")
		, m_Password("Heslo")
	{
	}

	DDWork::Network::UserRightType SimpleLoginManager::IsUserAllowed(std::string Username, std::string Password)
	{
		return Username == m_Username && Password == m_Password ? 
			DDWork::Network::UserRightType::Allowed : DDWork::Network::UserRightType::NotAllowed;
	}
}