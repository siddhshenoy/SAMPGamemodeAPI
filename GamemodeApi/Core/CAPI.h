#pragma once

#include <sampgdk/sampgdk.h>

#include "CGamemode.h"

class CAPI
{
public:
	static CGamemode* Gamemode;
public:
	static void InitGamemode();
	static void SetActiveGamemode(CGamemode* gamemode);
};

