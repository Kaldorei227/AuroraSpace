#pragma once
#include "../DDWork/Network/ILoginManager.h"

namespace Aurora::Impl //TODO: Delete this example element(in future)
{
	class SimpleLoginManager : public DDWork::Network::ILoginManager
	{
	public:
		SimpleLoginManager();

		// Inherited via ILoginManager
		DDWork::Network::UserRightType IsUserAllowed(std::string Username, std::string Password) override;

	private:
		std::string m_Username;
		std::string m_Password;
	};
}