namespace AuroraApplication.Network.Core
{
    public enum BaseMessType
    {
        Login = 1,
        HardBit = 2,
        Logger = 3,
        Other = 4
    }

    public struct BaseRequestHeaderMess
    {
        public string Key;
        public string Username;
        public string Password;
        public string InterfaceVersion;
        public BaseMessType Type;
    }

    public struct RequestMessageBase
    {
        public BaseRequestHeaderMess Head;
        public string Body;
    }

    /*************************************************/

    public struct AnswerMessageBase
    {
        public BaseMessType Type;
        public string Key;
        public string Answer;
    }
}
