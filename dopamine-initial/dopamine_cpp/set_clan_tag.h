#pragma once
#include "api.h"
#include "mem.h"

inline void fn_SetClanTag(std::string _tag)
{
	static auto fnClantagChanged = (int(__fastcall*)(const char*, const char*))PatternScan(GetModuleHandleA("engine.dll"), "53 56 57 8B DA 8B F9 FF 15");
	fnClantagChanged(_tag.c_str(), _tag.c_str());
}

std::string set_clan_tag(json args)
{
	std::string tag = std::string(args);
	tag = tag.substr(1, tag.find("]") - 2);

	fn_SetClanTag(tag);
	return "success";
}