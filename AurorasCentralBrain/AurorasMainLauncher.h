#pragma once
#include "Aurora/BaseAurorasObject.h"
#include <iostream>

namespace Aurora
{
	class AurorasMainLauncher
	{
	public:
		AurorasMainLauncher();
		~AurorasMainLauncher();

		void Launch();
	private:
		std::unique_ptr<BaseAurorasObject> m_BaseAurorasObject;

		//BaseAurorasObject
		//Logger
		//Config
		//ConsoleUI

		class AurorasLauncher
		{
			//UserDatabase
			//NEtwork
			//AICenter
			//BrainCenter

			//Doorcontroler
			//WindowControler
			//AgentControler
		};
	};
}