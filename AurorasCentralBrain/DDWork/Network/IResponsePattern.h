#pragma once
#include <iostream>
#include "../Events/IEvent.h"

namespace DDWork::Network
{
	class IResponsePattern
	{
	public:
		~IResponsePattern() = default;

		virtual void Release() = 0;

		virtual void SendString(std::string message) = 0;
		virtual std::string ReceiveString() = 0;

		virtual Events::IEvent<bool>& GetUserLogined() = 0;
	};
}