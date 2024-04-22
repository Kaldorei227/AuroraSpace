#pragma once
#include "../BaseAurorasObject.h"
#include "../DDWork/Network/IResponsePattern.h"
#include "../DDWork/Network/ILoginManager.h"

namespace Aurora::Impl	//TODO: Delete this example element(in future)
{
	class AuroraCommunication : public BaseAurorasObject //Info: This element is only example
	{
	public:
		AuroraCommunication();

		//BaseAurorasObject
		void Start() override;

	private:
		std::unique_ptr<DDWork::Network::IResponsePattern> m_Client;
		std::unique_ptr<DDWork::Network::ILoginManager> m_LoginManager;

		void OpenCommBridge();
	};
}