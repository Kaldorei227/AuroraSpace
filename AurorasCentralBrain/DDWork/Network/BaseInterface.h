#pragma once
#include <string>

namespace Aurora::DDWork::Network
{
    enum class BaseMessType
    {
        Login = 1,
        HardBit = 2,
        Logger = 3,
        Other = 4
    };

    struct BaseRequestHeaderMess
    {
        std::string Key;
        std::string Username;
        std::string Password;
        std::string InterfaceVersion;
        BaseMessType Type;
    };

    struct RequestMessageBase
    {
        BaseRequestHeaderMess Head;
        std::string Body;
    };

    /*************************************************/

    struct AnswerMessageBase
    {
        BaseMessType Type;
        std::string Key;
        std::string Answer;
    };
}