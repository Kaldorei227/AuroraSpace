#pragma once
#include <iostream>
#include "Logger/IBaseLogManager.h"

namespace Aurora
{
	class BaseAurorasObject
	{
	public:
		BaseAurorasObject(std::string elementName);

		virtual void Start() = 0;

	protected:
		void LogInfo(std::string info);
		void LogWarning(std::string warning);
		void LogError(std::string error);
		void LogCritical(std::string critical);

		std::string GetElementName();

	private:
		std::string m_ElementName;
		std::unique_ptr<Logger::IBaseLogManager> m_Logger;
	};
}