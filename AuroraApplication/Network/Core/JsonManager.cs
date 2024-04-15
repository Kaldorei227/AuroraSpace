namespace AuroraApplication.Network.Core
{
    using Newtonsoft.Json;

    public static class JsonManager
    {
        public static string RequestMessageBase2String(RequestMessageBase request)
        {
            return JsonConvert.SerializeObject(request);
        }
        public static AnswerMessageBase String2AnswerMessageBase(string json)
        {
            return JsonConvert.DeserializeObject<AnswerMessageBase>(json);
        }
    }
}
