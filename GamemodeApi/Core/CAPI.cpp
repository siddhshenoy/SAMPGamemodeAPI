#include "CAPI.h"

CGamemode* CAPI::Gamemode;

void CAPI::SetActiveGamemode(CGamemode* gamemode)
{
	CAPI::Gamemode = gamemode;
}