#pragma once
#include <string>

#include <sampgdk/sampgdk.h>

#define FCNPC_ENTITY_CHECK_NONE					(0)
#define FCNPC_ENTITY_CHECK_PLAYER				(1)
#define FCNPC_ENTITY_CHECK_NPC					(2)
#define FCNPC_ENTITY_CHECK_ACTOR				(4)
#define FCNPC_ENTITY_CHECK_VEHICLE				(8)
#define FCNPC_ENTITY_CHECK_OBJECT				(16)
#define FCNPC_ENTITY_CHECK_POBJECT_ORIG			(32)
#define FCNPC_ENTITY_CHECK_POBJECT_TARG			(64)
#define FCNPC_ENTITY_CHECK_MAP					(128)
#define FCNPC_ENTITY_CHECK_ALL					(255)

#define FCNPC_ENTITY_MODE_AUTO					(-1)
#define FCNPC_ENTITY_MODE_NONE					(0)
#define FCNPC_ENTITY_MODE_COLANDREAS			(1)

#define FCNPC_MOVE_TYPE_AUTO					(-1)
#define FCNPC_MOVE_TYPE_WALK					(0)
#define FCNPC_MOVE_TYPE_RUN						(1)
#define FCNPC_MOVE_TYPE_SPRINT					(2)
#define FCNPC_MOVE_TYPE_DRIVE					(3)

#define FCNPC_MOVE_MODE_AUTO					(-1)
#define FCNPC_MOVE_MODE_NONE					(0)
#define FCNPC_MOVE_MODE_MAPANDREAS				(1)
#define FCNPC_MOVE_MODE_COLANDREAS				(2)

#define FCNPC_MOVE_PATHFINDING_AUTO				(-1)
#define FCNPC_MOVE_PATHFINDING_NONE				(0)
#define FCNPC_MOVE_PATHFINDING_Z				(1)
#define FCNPC_MOVE_PATHFINDING_RAYCAST			(2)

#define FCNPC_MOVE_SPEED_AUTO					(-1.0)
#define FCNPC_MOVE_SPEED_WALK					(0.1552086)
#define FCNPC_MOVE_SPEED_RUN					(0.56444)
#define FCNPC_MOVE_SPEED_SPRINT					(0.926784)

#define FCNPC_MAX_NODES							(64)

#define FCNPC_INVALID_MOVEPATH_ID				(-1)
#define FCNPC_INVALID_RECORD_ID					(-1)


namespace Plugins
{
	namespace FCNPC
	{
		int GetPluginVersion(char* version, int length);

		int SetPosition(int npcid, float x, float y, float z);
		int GetPosition(int npcid, float* x, float* y, float* z);
		//mode = FCNPC_MOVE_MODE_AUTO, pathfinding = FCNPC_MOVE_PATHFINDING_AUTO, Float:radius = 0.0, bool:set_angle = true, Float:min_distance = 0.0, stop_delay = 250);
		int GoTo(int npcid, float x, float y, float z, int type = FCNPC_MOVE_TYPE_AUTO, float speed = FCNPC_MOVE_SPEED_AUTO, int mode = FCNPC_MOVE_MODE_AUTO, int pathfinding = FCNPC_MOVE_PATHFINDING_AUTO, float radius = 0.0f, bool set_angle = true, float min_distance = 0.0f, int stop_delay = 250);
		int GoToPlayer(int npcid, int playerid, int type = FCNPC_MOVE_TYPE_AUTO, float speed = FCNPC_MOVE_SPEED_AUTO, int mode = FCNPC_MOVE_MODE_AUTO, int pathfinding = FCNPC_MOVE_PATHFINDING_AUTO, float radius = 0.0f, bool set_angle = true, float min_distance = 0.0f, float dist_check = 1.5f, int stop_delay = 250);

		int Create(const char* npcname);
		int Destroy(int npcid);
		int Spawn(int npcid, int skinid, float x, float y, float z);
		int Respawn(int npcid);
		bool IsSpawned(int npcid);
		int Kill(int npcid);
		bool IsDead(int npcid);
		bool IsValid(int npcid);
		bool IsStreamedIn(int npcid, int forplayerid);

		int SetWeapon(int npcid, int weaponid);
		int SetAmmo(int npcid, int ammo);

		float GetHealth(int npcid);
		int SetHealth(int npcid, float health);

		int AimAtPlayer(int npcid, int playerid, bool shoot = false, int shoot_delay = -1, bool set_angle = true, float offset_x = 0.0f, float offset_y = 0.0f, float offset_z = 0.0f, float offset_from_x = 0.0f, float offset_from_y = 0.0f, float offset_from_z = 0.0f, int between_check_mode = FCNPC_ENTITY_MODE_AUTO, int between_check_flags = FCNPC_ENTITY_CHECK_ALL);
		int StopAim(int npcid);
		int SetKeys(int npcid, int ud_analog, int lr_analog, int keys);

		namespace Callbacks
		{
			bool OnReachDestination(int npcid);
			bool OnSpawn(int npcid);
			bool OnUpdate(int npcid);
		};
	};
};
//FCNPC_GoTo(npcid, Float:x, Float:y, Float:z, type = FCNPC_MOVE_TYPE_AUTO, Float:speed = FCNPC_MOVE_SPEED_AUTO, mode = FCNPC_MOVE_MODE_AUTO, pathfinding = FCNPC_MOVE_PATHFINDING_AUTO, Float:radius = 0.0, bool:set_angle = true, Float:min_distance = 0.0, stop_delay = 250);

/*
bool OnDynamicObjectMoved(int objectid);
bool OnPlayerEditDynamicObject(int playerid, int objectid, int response, float x, float y, float z, float rx, float ry, float rz);
bool OnPlayerSelectDynamicObject(int playerid, int objectid, int modelid, float x, float y, float z);
bool OnPlayerShootDynamicObject(int playerid, int weaponid, int objectid, float x, float y, float z);
bool OnPlayerPickUpDynamicPickup(int playerid, int pickupid);
bool OnPlayerEnterDynamicCP(int playerid, int checkpointid);
bool OnPlayerLeaveDynamicCP(int playerid, int checkpointid);
bool OnPlayerEnterDynamicRaceCP(int playerid, int checkpointid);
bool OnPlayerLeaveDynamicRaceCP(int playerid, int checkpointid);
bool OnPlayerEnterDynamicArea(int playerid, int areaid);
bool OnPlayerLeaveDynamicArea(int playerid, int areaid);
bool OnPlayerGiveDamageDynamicActor(int playerid, int actorid, float amount, int weaponid, int bodypart);
bool OnDynamicActorStreamIn(int actorid, int forplayerid);
bool OnDynamicActorStreamOut(int actorid, int forplayerid);
bool Streamer_OnItemStreamIn(int type, int id);
bool Streamer_OnItemStreamOut(int type, int id);
bool Streamer_OnPluginError(const char error[]);
*/