#include "FCNPC.h"
#include <sampgdk/sampgdk.h>



namespace Plugins
{
	namespace FCNPC
	{

		int GetPluginVersion(char* version, int length)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_GetPluginVersion");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "si", version, length);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}

		int SetPosition(int npcid, float x, float y, float z)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_SetPosition");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "ifff", npcid, x, y, z);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int GetPosition(int npcid, float* x, float* y, float* z)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_GetPosition");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "iRRR", npcid, x, y, z);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}

		int GoTo(int npcid, float x, float y, float z, int type, float speed, int mode, int pathfinding, float radius, bool set_angle, float min_distance, int stop_delay)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_GoTo");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "ifffifiifbfi", npcid, x, y, z, type, speed, mode, pathfinding, radius, set_angle, min_distance, stop_delay);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int GoToPlayer(int npcid, int playerid, int type, float speed, int mode, int pathfinding, float radius, bool set_angle, float min_distance, float dist_check, int stop_delay)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_GoToPlayer");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "iiifiifbffi", npcid, playerid, type, speed, mode, pathfinding, radius, set_angle, min_distance, dist_check, stop_delay);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int Create(const char* npcname)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_Create");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "s", npcname);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int Destroy(int npcid)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_Destroy");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "i", npcid);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int Spawn(int npcid, int skinid, float x, float y, float z)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_Spawn");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "iifff", npcid, skinid, x, y, z);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int Respawn(int npcid)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_Respawn");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "i", npcid);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		bool IsSpawned(int npcid)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_IsSpawned");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "i", npcid);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int Kill(int npcid)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_Kill");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "i", npcid);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		bool IsDead(int npcid)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_IsDead");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "i", npcid);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		bool IsValid(int npcid)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_IsValid");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "i", npcid);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		bool IsStreamedIn(int npcid, int forplayerid)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_IsStreamedIn");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "ii", npcid, forplayerid);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int SetKeys(int npcid, int ud_analog, int lr_analog, int keys)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_SetKeys");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "iiii", npcid, ud_analog, lr_analog, keys);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int SetWeapon(int npcid, int weaponid)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_SetWeapon");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "ii", npcid, weaponid);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int SetAmmo(int npcid, int ammo)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_SetAmmo");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "ii", npcid, ammo);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int AimAtPlayer(int npcid, int playerid, bool shoot, int shoot_delay, bool set_angle, float offset_x, float offset_y, float offset_z, float offset_from_x, float offset_from_y, float offset_from_z, int between_check_mode, int between_check_flags)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_AimAtPlayer");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "iibibffffffii", npcid, playerid, shoot, shoot_delay, set_angle, offset_x, offset_y, offset_z, offset_from_x, offset_from_y, offset_from_z, between_check_mode, between_check_flags);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int StopAim(int npcid)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_StopAim");
			if (Native != NULL) return sampgdk::InvokeNative(Native, "i", npcid);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		float GetHealth(int npcid)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_GetHealth");
			if (Native != NULL) return (float)sampgdk::InvokeNative(Native, "i", npcid);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
		int SetHealth(int npcid, float health)
		{
			static AMX_NATIVE Native = sampgdk::FindNative("FCNPC_SetHealth");
			if (Native != NULL) return (float)sampgdk::InvokeNative(Native, "if", npcid, health);
			else return sampgdk::logprintf("'" __FILE__ "' / '%s' - Function not discovered !", __func__), 0;
		}
	}
};

