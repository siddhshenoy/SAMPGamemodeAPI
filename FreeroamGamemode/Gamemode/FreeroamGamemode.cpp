//#include "JavascriptRuntime.h"
#include <Core/CAPI.h>
#include "Npc/CopNpc.h"
#include "Structures/PlayerStructure.h"

CopNpc* Npc;

class FreeroamGamemode : public CGamemode
{
public:
	JavascriptRuntime g_Runtime;
public:
	bool OnGamemodeInit()
	{
		CServer::UsePedAnims();
		CServer::AddDefaultPedClasses(1, 2, 3);
		g_Runtime.CreateRuntime();
		Npc = new CopNpc();
		Npc->AttachScript(L"./scriptfiles/npcscripts/CopNpc.js", g_Runtime);
		Npc->LoadNodeList("./scriptfiles/npcpaths.txt");
		Npc->DelayedSpawn("CopNpc", 1, CVector3f(0.0f, 0.0f, 3.0f));
		return true;
	}
	bool OnGamemodeExit()
	{
		delete Npc;
		return true;
	}
	bool OnPlayerConnect(CPlayer* Player)
	{
		PlayerStructure* pStruct = new PlayerStructure;
		Player->SetProperty("pStruct", (void*)(pStruct));
		return true;
	}
	bool OnPlayerDisconnect(CPlayer* Player, int Reason)
	{
		return true;
	}
	bool OnPlayerSpawn(CPlayer* Player)
	{
		Player->SetPosition(CVector3f(14.5091f, -205.0241f, 3.5178f));
		return true;
	}
	bool OnPlayerText(CPlayer* Player, const std::string& Text)
	{
		return true;
	}
	bool OnPlayerUpdate(CPlayer* Player)
	{
		return true;
	}
	bool OnPlayerRequestClass(CPlayer* Player, int classid)
	{
		Player->SetPosition(CVector3f(424.6650f, -1815.7747f, 6.6641f));
		Player->SetRotationZ(138.2162f);
		Player->Camera->SetPosition(CVector3f(419.5992f, -1821.1616f, 5.5019f));
		Player->Camera->SetLookAt(CVector3f(424.6650f, -1815.7747f, 6.6641f));
		return true;
	}
	bool OnPlayerCommandText(CPlayer* player, std::string command, std::vector<std::string> params)
	{
		sampgdk::logprintf("command: %s", command.c_str());
		sampgdk::logprintf("params size: %d", params.size());
		if (command == "/savenpcpath")
		{
			char pString[256];
			sprintf_s(pString, sizeof(pString), "%f, %f, %f\n", player->GetPosition().x, player->GetPosition().y, player->GetPosition().z);
			SendClientMessage(player->GetID(), -1, pString);
			PlayerStructure* ps = static_cast<PlayerStructure*>(player->GetProperty("pStruct"));
			ps->m_NpcWriteFile.open("./scriptfiles/npcpaths.txt", std::fstream::app);
			if (ps->m_NpcWriteFile.good())
			{
				ps->m_NpcWriteFile.write(pString, strlen(pString));
			}
			ps->m_NpcWriteFile.close();

			return true;
		}
		return false;
	}
};

void CAPI::InitGamemode()
{
	CAPI::SetActiveGamemode(new FreeroamGamemode());
}