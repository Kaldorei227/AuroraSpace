#include "ResponsePattern.h"
#include "../Json/JsonManager.h"

namespace Aurora::DDWork::Network
{
	ResponsePattern::ResponsePattern(std::string adress, ILoginManager& loginManager_)
		: m_LoginManager(loginManager_)
		, m_IsThreadRequired(true)
	{
		m_Client = std::make_unique<Core::ZmqDD>(adress, Core::PetternType::ResponsePattern);
		m_ReceivingThread = std::jthread([&] 
			{
				ReceivingThread();
			});
	}

	ResponsePattern::~ResponsePattern()
	{
		Release();
	}

	void ResponsePattern::Release()
	{
		m_IsThreadRequired = false;
		m_Client->ReleaseConnection();

		if (m_ReceivingThread.joinable())
			m_ReceivingThread.join();
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
		while (m_IsThreadRequired)
		{
			auto recMess = Json::JsonManager::DeSerialize<RequestMessageBase>(m_Client->ReceiveFrame(0));
			auto answerMess = ContinueByRequestType(recMess);
			m_Client->SendFrame(Json::JsonManager::Serialize<AnswerMessageBase>(answerMess), 0);
		}
	}

	AnswerMessageBase ResponsePattern::ContinueByRequestType(RequestMessageBase requestMess)
	{
		std::cout << "We got request: " << requestMess.Head.Username << std::endl;

		switch(requestMess.Head.Type)
		{
		case BaseMessType::Login:
			return TryLoginUser(requestMess.Head);
		case BaseMessType::HardBit:
			break;
		case BaseMessType::Logger:
			break;
		case BaseMessType::Other:
			break;
		}

		return AnswerMessageBase
		{
			BaseMessType::Login,
			"",
			"Access denide."
		};
	}

	AnswerMessageBase ResponsePattern::TryLoginUser(BaseRequestHeaderMess requestHead)
	{
		if (m_LoginManager.IsUserAllowed(requestHead.Username, requestHead.Password) == UserRightType::Allowed)
			return LoginedNewUser();

		return AnswerMessageBase
		{
			BaseMessType::Login,
			"",
			"Access denide."
		};
	}

	AnswerMessageBase ResponsePattern::LoginedNewUser()
	{
		return AnswerMessageBase
		{
			BaseMessType::Login,
			"uB99upJh4tWtFlzFPEbnX8zPZbLztXBLKpd",
			"Access granted."
		};
	}
}