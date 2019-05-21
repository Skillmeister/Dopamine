#pragma once
#include "api.h"

using function = std::string(*)(json);
inline std::map<std::string, function> function_list;

namespace functions
{
	void init();
}