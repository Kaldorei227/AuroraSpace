#pragma once
#include "IBaseLogManager.h"

namespace Aurora::Logger
{
	class BaseLogManager : public IBaseLogManager
	{
	public:
		BaseLogManager(std::string elementName);

		//IBaseLogManager
		void LogInfo(std::string info) override;
		void LogWarning(std::string warning) override;
		void LogError(std::string error) override;
		void LogCritical(std::string critical) override;
		void LogDeveloper(std::string dev) override;
	private:
		//Dopsat log system (thread safe)
	};
}