#include <stdio.h>
#include <string.h>
#include <array>
#include <time.h>

#include <sampgdk/sampgdk.h>
#include <Core/CAPI.h>
#include <Base/CNpc.h>
#include <Utils/StringFunctions.h>
#include <Utils/VectorFunctions.h>

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit()
{
#if defined		DEBUG
#endif
	CAPI::InitGamemode();
	return CAPI::Gamemode->OnGamemodeInit();
}
PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeExit()
{
#if defined		DEBUG
#endif
	//CPool::DeallocateVehicles();
	//return CAPI::Gamemode->OnGamemodeExit();
	//CPool::DeallocatePlayerList();
	sampgdk::logprintf("onGamemodeexit called..");
	return CAPI::Gamemode->OnGamemodeExit();
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerConnect(int playerid)
{
#if defined		DEBUG
#endif
	if (!IsPlayerNPC(playerid))
	{
		CPool::AllocatePlayer(playerid);
		return CAPI::Gamemode->OnPlayerConnect(CPool::GetPlayerFromId(playerid));
	}
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerDisconnect(int playerid, int reason)
{
#if defined		DEBUG
#endif
	if(!IsPlayerNPC(playerid))
	{	
		CPlayer* Player = CPool::GetPlayerFromId(playerid);
		bool Result = CAPI::Gamemode->OnPlayerDisconnect(Player, reason);
		CPool::DeallocatePlayer(playerid);
		return Result;
	}
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerSpawn(int playerid)
{
#if defined		DEBUG
#endif
	CPlayer* Player = CPool::GetPlayerFromId(playerid);
	return CAPI::Gamemode->OnPlayerSpawn(Player);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerStateChange(int playerid, int newstate, int oldstate)
{
#if defined		DEBUG
#endif
	//CPlayer* Player = CPool::GetPlayerFromID(playerid);
	//if ((oldstate != PLAYER_STATE_DRIVER && newstate == PLAYER_STATE_DRIVER) || (oldstate != PLAYER_STATE_PASSENGER && newstate == PLAYER_STATE_PASSENGER))
	//{
	//	int VehicleID = GetPlayerVehicleID(playerid);
	//	if (CPool::HasVehicleID(VehicleID))
	//	{
	//		CVehicle* Vehicle = CPool::GetVehicleFromID(VehicleID);
	//		Player->SetVehicle(Vehicle);
	//	}
	//	else
	//	{
	//		sampgdk::logprintf("OnPlayerStateChange: Vehicle assignment error. Player %d could not be assigned the vehicle id %d as it was not present in the pool.", playerid, VehicleID);
	//	}
	//}
	//else if ((oldstate == PLAYER_STATE_DRIVER && newstate != PLAYER_STATE_DRIVER) || (oldstate == PLAYER_STATE_PASSENGER && newstate != PLAYER_STATE_PASSENGER))
	//{
	//	Player->SetVehicle(NULL);
	//}
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnDialogResponse(int playerid, int dialogid, int response, int listitem, const char* inputtext)
{
#if defined		DEBUG
#endif
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerRequestClass(int playerid, int classid)
{
#if defined		DEBUG
#endif
	/*SetPlayerPos(playerid, 424.6650f, -1815.7747f, 6.6641f);
	SetPlayerFacingAngle(playerid, 138.2162f);
	SetPlayerCameraPos(playerid, 419.5992, -1821.1616, 5.5019);
	SetPlayerCameraLookAt(playerid, 424.6650f, -1815.7747f, 6.6641f, CAMERA_CUT);*/
	CPlayer* Player = CPool::GetPlayerFromId(playerid);
	return CAPI::Gamemode->OnPlayerRequestClass(Player, classid);
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerCommandText(int playerid, const char* cmdtext)
{
#if defined		DEBUG
#endif
	//std::vector<std::string> CommandSplits = StringFuncs::Split(cmdtext, ' ');
	//std::vector<std::string> Parameters = VectorFuncs::CopyStringVector(CommandSplits, 1, -1);
	//std::string Command = CommandSplits[0];
	//CPlayer* player = CPool::GetPlayerFromID(playerid);
	//if (player != NULL) {
	//	return CCommandProcessor::ExecuteCommand(player, Command, Parameters);
	//}
	//return CAPI::Gamemode->OnPlayerCommandText(;
	std::vector<std::string> Splits = Utils::String::Split(cmdtext, ' ');
	std::vector<std::string> Params = std::vector<std::string>();
	std::string Command = "";
	if (Splits.size() >= 1) {
		Command = Splits[0];
	}
	if (Splits.size() > 1) {
		Params = Utils::Vector::CreateVector<std::string>(Splits, 1, Splits.size());
	}
	CPlayer* Player = CPool::GetPlayerFromId(playerid);
	return CAPI::Gamemode->OnPlayerCommandText(Player, Command, Params);
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerDeath(int playerid, int killerid, int reason)
{
#if defined		DEBUG
#endif
	return true;

}
PLUGIN_EXPORT bool PLUGIN_CALL OnVehicleSpawn(int vehicleid)
{
#if defined		DEBUG
#endif
	//CVehicle* Vehicle = CPool::m_VehiclePool[vehicleid];
	//sampgdk::logprintf("OnVehicleSpawn (%x) (VehicleID: %d)", Vehicle, Vehicle->GetId());
	//return CAPI::Gamemode->OnVehicleSpawn(Vehicle);
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnVehicleDeath(int vehicleid, int killerid)
{
#if defined		DEBUG
#endif
	// 18th April 2021 10:12 Left from here...
	//sampgdk::logprintf("OnVehicleDeath (%x)");
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerText(int playerid, const char* text)
{
#if defined		DEBUG
#endif
	//CPlayer* player = CPool::GetPlayerFromID(playerid);
	//return CAPI::Gamemode->OnPlayerText(player, std::string(text));
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerEnterVehicle(int playerid, int vehicleid, bool ispassenger)
{
#if defined		DEBUG
#endif
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerExitVehicle(int playerid, int vehicleid)
{
#if defined		DEBUG
#endif
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerClickPlayer(int playerid, int clickedplayerid, int source)
{
#if defined		DEBUG
#endif
	return 1;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerEnterCheckpoint(int playerid)
{
#if defined		DEBUG
#endif
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerLeaveCheckpoint(int playerid)
{
#if defined		DEBUG
#endif
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerEnterRaceCheckpoint(int playerid)
{
#if defined		DEBUG
#endif
	return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerLeaveRaceCheckpoint(int playerid)
{
#if defined		DEBUG
#endif
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerRequestSpawn(int playerid)
{
#if defined		DEBUG
#endif

	return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerUpdate(int playerid)
{
#if defined		DEBUG
#endif
	/*CPlayer* player = CPool::GetPlayerFromID(playerid);
	return CAPI::Gamemode->OnPlayerUpdate(player);*/
	return true;
}
PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerKeyStateChange(int playerid, int newkeys, int oldkeys)
{
#if defined DEBUG
#endif
	return true;
}

/**
	PLUGIN CALLS
**/

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
	return sampgdk::Supports() | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData) {
	return sampgdk::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
	sampgdk::Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
	sampgdk::ProcessTick();
}

bool Plugins::FCNPC::Callbacks::OnSpawn(int npcid)
{
	return CPool::NpcPool[npcid]->OnSpawn();
}

bool Plugins::FCNPC::Callbacks::OnReachDestination(int npcid)
{
	return CPool::NpcPool[npcid]->OnReachDestination();
}

bool Plugins::FCNPC::Callbacks::OnUpdate(int npcid)
{
	return CPool::NpcPool[npcid]->OnUpdate();
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPublicCall(AMX* amx, const char* name, cell* params, cell* retval)
{

	std::string lName = std::string(name);
	if (lName == "FCNPC_OnReachDestination") { 
		return Plugins::FCNPC::Callbacks::OnReachDestination(static_cast<int>(params[1]));
	}
	else if (lName == "FCNPC_OnSpawn") { 
		return Plugins::FCNPC::Callbacks::OnSpawn(static_cast<int>(params[1]));
	}
	else if (lName == "FCNPC_OnUpdate") {
		return Plugins::FCNPC::Callbacks::OnUpdate(static_cast<int>(params[1]));
	}
	return 1;
}