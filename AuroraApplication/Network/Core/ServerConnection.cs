namespace AuroraApplication.Network.Core
{
    using NetMQ;
    using NetMQ.Sockets;

    public class ServerConnection
    {
        private RequestSocket server;

        public ServerConnection(string ip, string port)
        {
            server = new RequestSocket($">tcp://{ip}:{port}");
        }

        public bool Login(string username, string password)
        {
            server.SendFrame(JsonManager.RequestMessageBase2String(GetLoginStructure(username, password)));
            var answer = JsonManager.String2AnswerMessageBase(server.ReceiveFrameString());

            if (answer.Key != "")
                return true;

            return false;
        }

        private RequestMessageBase GetLoginStructure(string username, string password)
        {
            var head = new BaseRequestHeaderMess
            {
                Key = "",
                Username = username,
                Password = password,
                InterfaceVersion = "",
                Type = BaseMessType.Login
            };
            return new RequestMessageBase
            {
                Head = head,
                Body = "Please let me in"
            };
        }
    }
}
