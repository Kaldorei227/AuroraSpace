#include <iostream>
#include "DDWork/Network/ResponsePattern.h" //TODO: Vymazat
#include "DDWork/Events/EventGuard.h"
#include "DDWork/Events/IEventGuard.h"
#include "DDWork/Events/Event.h"
#include "DDWork/Events/IEvent.h"

struct CustomS
{
    double ID;
};

int main()
{
    std::cout << "Hello World!\n";

    CustomS ah{};
    Aurora::DDWork::Events::Event<CustomS> myEvent;

    myEvent(ah);

    Aurora::DDWork::Events::EventGuard<CustomS> guard;

    guard.Register(myEvent, [](CustomS aa) {});

    std::cout << "DONE" << std::endl;
    int i;
    std::cin >> i;
}