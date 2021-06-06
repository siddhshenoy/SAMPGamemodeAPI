#include "CNpc.h"

CNpc::CNpc()
{
	m_ID = -1;
	m_NpcScriptLoaded = false;
}
void CNpc::CreateNpc(const std::string& name, int modelid)
{
	m_ID = Plugins::FCNPC::Create(name.c_str());
	SetModel(modelid);
	CPool::NpcPool.insert( std::pair<int, CNpc*>(m_ID, this) );
	if (m_NpcScriptLoaded)
		m_NpcCode.CallJSFunction("OnNpcCreate", JavascriptCode::GetDefaultArgs());
}
void CNpc::Spawn(CVector3f Position)
{
	Plugins::FCNPC::Spawn(m_ID, GetModel(), Position.x, Position.y, Position.z);
	
}
void CNpc::DelayedSpawn(const std::string& name, int modelid, CVector3f Position)
{
	SetName(name);
	SetModel(modelid);
	SetSpawnPosition(Position);
	void* params = (void*)this;
	SetTimer(1000, 0, CNpc::DelayedSpawnTimer, params);
}
void CNpc::Goto(CVector3f Position, int Type)
{
	Plugins::FCNPC::GoTo(m_ID, Position.x, Position.y, Position.z, Type);
}
CNpc::~CNpc()
{
	Plugins::FCNPC::Destroy(m_ID);
}

void CNpc::AttachScript(const std::wstring& scriptpath, JavascriptRuntime& RT)
{
	sampgdk::logprintf("Loading script..");
	m_NpcContext.CreateContext(RT);
	m_NpcCode.SetContext(m_NpcContext);
	m_NpcCode.SetCodeFile(scriptpath);
	m_NpcCode.CreateHostObject(L"SAMP");
	m_NpcCode.AttachHostObjectFunction(L"SAMP", L"Print", JsFunctions::SAMPAPI_Print, nullptr);
	m_NpcCode.AttachHostObjectFunction(L"SAMP", L"GetMaxPlayers", JsFunctions::SAMPAPI_GetMaxPlayers, nullptr);
	m_NpcCode.AttachHostObjectFunction(L"SAMP", L"IsPlayerNpc", JsFunctions::SAMPAPI_IsPlayerNpc, nullptr);
	m_NpcCode.AttachHostObjectFunction(L"SAMP", L"GetPlayerPos", JsFunctions::SAMPAPI_GetPlayerPos, nullptr);
	m_NpcCode.AttachHostObjectFunction(L"SAMP", L"IsPlayerConnected", JsFunctions::SAMPAPI_IsPlayerConnected, nullptr);
	m_NpcCode.Run();
	m_NpcScriptLoaded = true;
	sampgdk::logprintf("Done loading script..");
}
//Timers

void CNpc::DelayedSpawnTimer(int timerid, void* params)
{
	CNpc* Npc = (CNpc*)(params);
	Npc->CreateNpc(Npc->GetName(), Npc->GetModel());
	Npc->Spawn(Npc->GetSpawnPosition());
}
void CNpc::SetName(const std::string& name)
{
	m_Name = name;
}
std::string CNpc::GetName()
{
	return m_Name;
}
void CNpc::SetSpawnPosition(CVector3f Position)
{
	m_SpawnPosition = Position;
}
CVector3f CNpc::GetSpawnPosition()
{
	return m_SpawnPosition;
}