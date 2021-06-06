#pragma once

#include <unordered_map>
#include <Base/CPlayer.h>
#include <Base/CVehicle.h>


class CNpc;

class CPool
{
public:
	static std::unordered_map<int, CPlayer*> PlayerPool;
	static std::unordered_map<int, CNpc*> NpcPool;
public:
	static void AllocatePlayer(int id);
	static void DeallocatePlayer(int id);
	static bool PlayerExists(int id);
	static CPlayer* GetPlayerFromId(int id);
	static void DeallocatePlayerList();
public:
	static CVehicle* CreateVehicle(int modelid, float x, float y, float z, float angle, int color1, int color2);

};

