#pragma once
#include "IEventGuard.h"
#include <iostream>

namespace Aurora::DDWork::Events
{
	template<typename T>
	class EventGuard : public IEventGuard<T>
	{
	public:
		EventGuard(): eventID(0) {}
		~EventGuard()
		{
			m_EventOwner->UnRegister(eventID);
		}

		void Register(IEvent<T>& eventOwner, std::function<void(T)> func) override
		{
			*m_EventOwner = eventOwner;
			eventID = m_EventOwner->Register(func);
		}

	private:
		IEvent<T> *m_EventOwner;
		int eventID;
	};
}