#pragma once
#include <functional>

namespace DDWork::Events
{
	template<class T>
	class IEvent
	{
	public:
		virtual ~IEvent() = default;

		virtual int Register(std::function<void(T)> func) = 0;
		virtual void UnRegister(int) = 0;
		virtual void operator() (T) = 0;
	};
}