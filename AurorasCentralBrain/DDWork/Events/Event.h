#pragma once
#include "IEvent.h"
#include <unordered_map>
#include <vector>
#include <atomic>
#include <thread>

namespace DDWork::Events
{
    template<typename T>
    class Event : public IEvent<T>
    {
    public:
        Event() : m_EventCounter(0) {}

        int Register(std::function<void(T)> func) override
        {
            int newID = m_EventCounter;
            m_EventList[newID] = func;
            m_EventCounter++;
            return newID;
        }

        void UnRegister(int ID) override
        {
            m_EventList.erase(ID);
        }

        void operator()(T value) override
        {
            if (m_EventsThread.joinable())
                m_EventsThread.join();

            m_EventsThread = std::jthread([&]
                {
                    for (const auto& [key, eventElm] : m_EventList)
                    {
                        eventElm(value);
                    }
                });
        }

    private:
        std::unordered_map<int, std::function<void(T)>> m_EventList;
        int m_EventCounter;
        std::jthread m_EventsThread;
    };
}