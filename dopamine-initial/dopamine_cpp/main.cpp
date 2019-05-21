#include <fstream>
#include "common.h"

DWORD WINAPI attach(LPVOID base)
{
	std::ifstream config(std::string(getenv("APPDATA")).append("\\dopamine"));

	if (!config.good())
	{
		MessageBoxA(NULL, "Unable to get config folder. Did you follow instructions?", "Error", NULL);
		return 0;
	}

	std::string config_folder;
	config >> config_folder;

	functions::init();
	communication::init(config_folder);

	return 0;
}

BOOL WINAPI DllMain(
	_In_      HINSTANCE hinstDll,
	_In_      DWORD     fdwReason,
	_In_opt_  LPVOID    lpvReserved
)
{
	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hinstDll);
		CreateThread(nullptr, 0, attach, hinstDll, 0, nullptr);
		return TRUE;
	default:
		return TRUE;
	}
}