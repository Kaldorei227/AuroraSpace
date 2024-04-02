using AuroraApplication.Models;

namespace AuroraApplication.Repositories
{
    public class UserRepository : IUserRepository
    {
        private UserModel _user = new UserModel();

        public UserRepository()
        {
            _user.Id = "ISKD224KJ";
            _user.Username = "Kaldorei";
            _user.Password = "Heslo";
            _user.Name = "Dominik";
            _user.LastName = "Dusek";
        }

        public bool AuthenticateUser(string username, string password)
        {
            return username == _user.Username && password == _user.Password;
        }

        public UserModel GetByUserName(string username)
        {
            return _user;
        }
    }
}
