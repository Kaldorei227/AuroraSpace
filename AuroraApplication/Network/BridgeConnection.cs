using AuroraApplication.Network.Core;

namespace AuroraApplication.Network
{

    public class BridgeConnection
    {
        private ServerConnection _Server;

        public BridgeConnection()
        {
            _Server = new ServerConnection();
        }

        public bool Login(string username, string password)
        {
            return _Server.Login(username, password);
        }
    }
}
