#pragma once
#include <exception>

namespace DDWork::Network::Core::Exception
{
	class NetworkBaseException : public std::exception
	{
	public:
		NetworkBaseException(const char* what) : std::exception(what) {}
	};

	class ReceiveMessageRequired : public NetworkBaseException
	{
	public:
		ReceiveMessageRequired(const char* what) : NetworkBaseException(what) {}
	};

	class SendMessageRequired : public NetworkBaseException
	{
	public:
		SendMessageRequired(const char* what) : NetworkBaseException(what) {}
	};
}