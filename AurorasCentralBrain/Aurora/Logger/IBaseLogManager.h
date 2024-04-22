#pragma once
#include <iostream>

namespace Aurora::Logger
{
	class IBaseLogManager
	{
	public:
		virtual void LogInfo(std::string info) = 0;
		virtual void LogWarning(std::string warning) = 0;
		virtual void LogError(std::string error) = 0;
		virtual void LogCritical(std::string critical) = 0;
		virtual void LogDeveloper(std::string dev) = 0;
	};
}