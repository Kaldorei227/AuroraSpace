#include "BaseAurorasObject.h"
#include "Logger/BaseLogManager.h"

namespace Aurora
{
	BaseAurorasObject::BaseAurorasObject(std::string elementName)
		: m_ElementName(elementName)
	{
		m_Logger = std::make_unique<Logger::BaseLogManager>(elementName);
	}

	void BaseAurorasObject::LogInfo(std::string info)
	{
		m_Logger->LogInfo(info);
	}

	void BaseAurorasObject::LogWarning(std::string warning)
	{
		m_Logger->LogWarning(warning);
	}

	void BaseAurorasObject::LogError(std::string error)
	{
		m_Logger->LogError(error);
	}

	void BaseAurorasObject::LogCritical(std::string critical)
	{
		m_Logger->LogCritical(critical);
	}

	std::string BaseAurorasObject::GetElementName()
	{
		return m_ElementName;
	}
}