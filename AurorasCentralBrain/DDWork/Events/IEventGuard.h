#pragma once
#include "IEvent.h"
#include <functional>

namespace DDWork::Events
{
	template<class T>
	class IEventGuard
	{
	public:
		virtual ~IEventGuard() = default;

		virtual void Register(IEvent<T>& eventOwner, std::function<void(T)> func) = 0;
	};
}