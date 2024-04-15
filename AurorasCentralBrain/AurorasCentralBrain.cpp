#include "stdafx.h"
#include <iostream>

using namespace Aurora::DDWork::Network;

int main()
{
    std::cout << "Hello World!\n";

    ResponsePattern m_Client("tcp://*:5555");

    std::cout << "Connection created" << std::endl;
    int i;
    std::cin >> i;
    std::cout << "Connection releasing" << std::endl;

    m_Client.Release();
    std::cout << "Connection closed" << std::endl;

}