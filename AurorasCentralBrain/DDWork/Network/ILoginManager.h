#pragma once
#include <iostream>
#include "Common.h"

namespace Aurora::DDWork::Network
{
	class ILoginManager
	{
	public:
		virtual UserRightType IsUserAllowed(std::string Username, std::string Password) = 0;
	};
}