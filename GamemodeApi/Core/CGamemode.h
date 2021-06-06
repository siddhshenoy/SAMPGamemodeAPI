#pragma once


#include "Base/CPool.h"
#include "Base/CServer.h"

class CGamemode
{
public:
	virtual bool OnGamemodeInit() = 0;
	virtual bool OnGamemodeExit() = 0;
	virtual bool OnPlayerConnect(CPlayer*) = 0;
	virtual bool OnPlayerDisconnect(CPlayer*, int) = 0;
	virtual bool OnPlayerSpawn(CPlayer*) = 0;
	virtual bool OnPlayerText(CPlayer*, const std::string&) = 0;
	virtual bool OnPlayerUpdate(CPlayer*) = 0;
	virtual bool OnPlayerRequestClass(CPlayer*, int) = 0;
	virtual bool OnPlayerCommandText(CPlayer*, std::string command, std::vector<std::string> params) = 0;
//	virtual bool OnVehicleSpawn(CVehicle*) = 0;
//	virtual bool OnVehicleDeath(CVehicle*) = 0;
};

