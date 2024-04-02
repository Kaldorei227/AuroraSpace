namespace AuroraApplication.Models
{
    public interface IUserRepository
    {
        bool AuthenticateUser(string username, string password);
        UserModel GetByUserName(string username);
    }
}
