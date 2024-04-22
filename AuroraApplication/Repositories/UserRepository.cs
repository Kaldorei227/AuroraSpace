using AuroraApplication.Models;
using AuroraApplication.Network;

namespace AuroraApplication.Repositories
{
    public class UserRepository : IUserRepository
    {
        private UserModel _user = new UserModel();
        private BridgeConnection _bridgeConnection;

        public UserRepository()
        {
            _bridgeConnection = new BridgeConnection();

            _user.Id = "ISKD224KJ";
            _user.Username = "Kaldorei";
            _user.Password = "Heslo";
            _user.Name = "Dominik";
            _user.LastName = "Dusek";
        }

        public bool AuthenticateUser(string username, string password)
        {
            return _bridgeConnection.Login(username, password);
        }

        public UserModel GetByUserName(string username)
        {
            return _user;
        }
    }
}
