#include "ZmqDD.h"
#include <assert.h>
#include <vector>

namespace Aurora::DDWork::Network::Core
{
	ZmqDD::ZmqDD(std::string stringAddres, PetternType type)
	{
		m_ZmqContext = std::make_unique<void*>(zmq_ctx_new());
		m_ZmqSocket = CreateSocketConnection(type);

		int rc = zmq_bind(*m_ZmqSocket, String2CharArray(stringAddres));
		assert(rc == 0);
	}

	ZmqDD::~ZmqDD()
	{
		ReleaseConnection();
	}

	void ZmqDD::SendFrame(std::string message, int flags)
	{
		if (m_NeedReceiveMessage)
			throw std::runtime_error("ZmqDD need receive message before!"); //TODO: Vytvorit vlastni exeptions

		auto msgLenght = message.length();
		auto* msg = String2CharArray(message);

		int rc = zmq_send(*m_ZmqSocket, msg, msgLenght, flags);
		assert(rc == msgLenght);

		m_NeedReceiveMessage = true;
	}

	std::string ZmqDD::ReceiveFrame(int flags)
	{
		if (!m_NeedReceiveMessage)
			throw std::runtime_error("ZmqDD need send message before!");

		zmq_msg_t msg;
		int rc = zmq_msg_init(&msg);
		assert(rc == 0);

		rc = zmq_recvmsg(*m_ZmqSocket, &msg, flags);
		assert(rc != -1);

		auto result = GetStringFromZmqMsg(msg);

		rc = zmq_msg_close(&msg);
		assert(rc == 0);

		m_NeedReceiveMessage = false;
		return result;
	}

	void ZmqDD::ReleaseConnection()
	{
		int rc = zmq_close(*m_ZmqSocket);
		assert(rc == 0);

		rc = zmq_ctx_term(*m_ZmqContext);
		assert(rc == 0);
	}

	std::optional<std::string> ZmqDD::TryReceiveFrame(int flags)
	{
		zmq_pollitem_t item[] =
		{
			{*m_ZmqSocket, 0, ZMQ_POLLIN, 0}
		};

		auto rc = zmq_poll(&item[0], 1, 100);
		assert(rc >= 0);

		if (item[0].revents & ZMQ_POLLIN)
		{
			return std::optional<std::string>(ReceiveFrame(flags));
		}
		else
		{
			return std::optional<std::string>{};
		}
	}

	bool ZmqDD::TrySendFrame(std::string message, int flags)
	{
		if (m_NeedReceiveMessage)
			throw std::runtime_error("ZmqDD need receive message before!");

		auto msgLenght = message.length();
		auto* msg = String2CharArray(message);

		int rc = zmq_send(*m_ZmqSocket, msg, msgLenght, flags);

		if (rc == msgLenght)
		{
			m_NeedReceiveMessage = true;
			return true;
		}

		return false;
	}

	std::unique_ptr<void*> ZmqDD::CreateSocketConnection(PetternType type)
	{
		switch (type)
		{
		case PetternType::RequestPattern:
			m_NeedReceiveMessage = false;
			return std::make_unique<void*>(zmq_socket(*m_ZmqContext, ZMQ_REQ));
		case PetternType::ResponsePattern:
			m_NeedReceiveMessage = true;
			return std::make_unique<void*>(zmq_socket(*m_ZmqContext, ZMQ_REP));
		case PetternType::PublishPattern:
			m_NeedReceiveMessage = false;
			return std::make_unique<void*>(zmq_socket(*m_ZmqContext, ZMQ_PUB));
		case PetternType::SubscribePattern:
			m_NeedReceiveMessage = true;
			return std::make_unique<void*>(zmq_socket(*m_ZmqContext, ZMQ_SUB));
		default:
			throw std::runtime_error("Undefine PatternType");
		}
	}

	char* ZmqDD::String2CharArray(std::string msg)
	{
		auto msgLength = msg.length() + 1;
		char* result = new char[msgLength];

#pragma warning(disable:4996)
		std::strcpy(result, msg.c_str());

		return result;
	}

	std::string ZmqDD::GetStringFromZmqMsg(zmq_msg_t msg)
	{
		std::vector<char> inMessage(zmq_msg_size(&msg));
		std::memcpy(inMessage.data(), zmq_msg_data(&msg), zmq_msg_size(&msg));

		std::string result(inMessage.begin(), inMessage.end());

		return result;
	}
}