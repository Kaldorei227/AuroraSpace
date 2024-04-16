#include "JsonManager.h"
#include "../Network/BaseInterface.h"

namespace DDWork::Json
{
	template<>
	Network::RequestMessageBase JsonManager::DeSerialize(std::string string)
	{
		json j = json::parse(string);
		json head = j["Head"];
		Network::BaseRequestHeaderMess headMess
		{
			head["Key"].template get<std::string>(),
			head["Username"].template get<std::string>(),
			head["Password"].template get<std::string>(),
			head["InterfaceVersion"].template get<std::string>(),
			head["Type"].template get<Network::BaseMessType>()
		};
		return Network::RequestMessageBase
		{
			headMess,
			j["Body"].template get<std::string>()
		};
	}

	template<>
	std::string JsonManager::Serialize(Network::RequestMessageBase object)
	{
		json head;
		head["Key"] = object.Head.Key;
		head["Username"] = object.Head.Username;
		head["Password"] = object.Head.Password;
		head["InterfaceVersion"] = object.Head.InterfaceVersion;
		head["Type"] = object.Head.Type;
		json request;
		request["Head"] = head;
		request["Body"] = object.Body;
		return request.dump();
	}
	/*********************************************************/
	template<>
	Network::AnswerMessageBase JsonManager::DeSerialize(std::string string)
	{
		json j = json::parse(string);
		return Network::AnswerMessageBase
		{
			j["Type"].template get<Network::BaseMessType>(),
			j["Key"].template get<std::string>(),
			j["Answer"].template get<std::string>()
		};
	}

	template<>
	std::string JsonManager::Serialize(Network::AnswerMessageBase object)
	{
		json j;
		j["Type"] = object.Type;
		j["Key"] = object.Key;
		j["Answer"] = object.Answer;
		return j.dump();
	}
}