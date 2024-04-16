#pragma once
#include <iostream>
#include "json.hpp"

namespace DDWork::Json
{
	class JsonManager
	{
	public:
		using json = nlohmann::json;

		template<class T>
		static T DeSerialize(std::string string);

		template<class T>
		static std::string Serialize(T object);
	};
}