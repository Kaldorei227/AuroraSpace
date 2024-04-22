#include "BaseLogManager.h"


namespace Aurora::Logger
{
	BaseLogManager::BaseLogManager(std::string elementName)
	{
	}

	void BaseLogManager::LogInfo(std::string info)
	{
		throw std::runtime_error("BaseLogManager::LogInfo not implemented");
	}

	void BaseLogManager::LogWarning(std::string warning)
	{
		throw std::runtime_error("BaseLogManager::LogWarning not implemented");
	}

	void BaseLogManager::LogError(std::string error)
	{
		throw std::runtime_error("BaseLogManager::LogError not implemented");
	}

	void BaseLogManager::LogCritical(std::string critical)
	{
		throw std::runtime_error("BaseLogManager::LogCritical not implemented");
	}

	void BaseLogManager::LogDeveloper(std::string dev)
	{
		throw std::runtime_error("BaseLogManager::LogDeveloper not implemented");
	}
}