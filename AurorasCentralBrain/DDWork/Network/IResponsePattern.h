#pragma once
#include <iostream>
#include "../Events/IEvent.h"

namespace Aurora::DDWork::Network
{
	class IResponsePattern
	{
	public:
		~IResponsePattern() = default;

		virtual void SendString(std::string message) = 0;
		virtual std::string ReceiveString() = 0;

		virtual Events::IEvent<bool>& GetUserLogined() = 0;
	};
}