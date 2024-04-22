#pragma once
#include <iostream>
#include "Common.h"

namespace DDWork::Network
{
	class ILoginManager
	{
	public:
		virtual UserRightType IsUserAllowed(std::string Username, std::string Password) = 0;
	};
}