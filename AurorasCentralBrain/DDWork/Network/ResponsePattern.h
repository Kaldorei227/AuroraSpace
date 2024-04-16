#pragma once
#include "IResponsePattern.h"
#include "ILoginManager.h"
#include "BaseInterface.h"
#include "Core/ZmqDD.h"
#include "../Events/Event.h"
#include <thread>
#include <atomic>

namespace DDWork::Network
{
	class ResponsePattern : public IResponsePattern
	{
	public:
		ResponsePattern(std::string adress, ILoginManager& loginManager_);
		~ResponsePattern();

		void Release() override;

		void SendString(std::string message) override;
		std::string ReceiveString() override;

		Events::IEvent<bool>& GetUserLogined() override;
	private:
		ILoginManager& m_LoginManager;
		std::unique_ptr<Core::ZmqDD> m_Client;
		Events::Event<bool> m_UserLoginedEvent;

		std::jthread m_ReceivingThread;
		std::atomic_bool m_IsThreadRequired;

		void ReceivingThread();
		AnswerMessageBase ContinueByRequestType(RequestMessageBase requestMess);
		AnswerMessageBase TryLoginUser(BaseRequestHeaderMess requestHead);
		AnswerMessageBase LoginedNewUser();
	};
}