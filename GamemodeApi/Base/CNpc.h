#pragma once


#include "JavascriptRuntime.h"
#include "JavascriptContext.h"
#include "JavascriptCode.h"
#include "JsFunctions.h"

#include <string>
#include "Entity/CNpcEntity.h"
#include "CPool.h"







struct DelayedSpawnParams
{
	
	int Model;
	CVector3f SpawnPosition;
	CNpc* Npc;
	std::string NpcName;
};

class CNpc : public CNpcEntity
{
private:
	JavascriptContext m_NpcContext;
	JavascriptCode m_NpcCode;
	bool m_NpcScriptLoaded;
private:
	std::string m_Name;
	CVector3f m_SpawnPosition;
public:
	void SetName(const std::string& name);
	void SetSpawnPosition(CVector3f Position);
	std::string GetName();
	CVector3f GetSpawnPosition();
public:
	CNpc();
	void CreateNpc(const std::string& name, int modelid);
	void Spawn(CVector3f Position);
	void DelayedSpawn(const std::string& name, int modelid, CVector3f Position);
	void Goto(CVector3f Position, int Type);
	void AttachScript(const std::wstring& scriptpath,JavascriptRuntime& Runtime);
	virtual ~CNpc();
public:
	virtual bool OnSpawn() {
		sampgdk::logprintf("Npc spawn called..\r\n");
		if (m_NpcScriptLoaded)
			m_NpcCode.CallJSFunction("OnNpcSpawn", JavascriptCode::GetDefaultArgs());
		return true;
	}
	virtual bool OnReachDestination() {
		if (m_NpcScriptLoaded)
			m_NpcCode.CallJSFunction("OnNpcReachDestination", JavascriptCode::GetDefaultArgs());
		return true;
	}
	virtual bool OnUpdate()
	{
		return true;
	}
public:
	static void DelayedSpawnTimer(int timerid, void* params);
};

