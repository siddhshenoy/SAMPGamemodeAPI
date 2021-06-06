#pragma once

#include "Base/CNpc.h"
#include "Utils/StringFunctions.h"

#include <fstream>

using namespace Utils::String;




class CopNpc : public CNpc
{
private:
	int m_LastUpdateTime;
	int m_CurrentNodeListTarget = 0;
	std::vector<CVector3f> m_NodeList;
public:
	CopNpc();
	void LoadNodeList(const std::string& NodeListPath);

	~CopNpc();
public:
	bool OnSpawn() override
	{
		CNpc::OnSpawn();
		Goto(m_NodeList[m_CurrentNodeListTarget], FCNPC_MOVE_TYPE_WALK);
		return true;
	}
	bool OnReachDestination() override
	{
		CNpc::OnReachDestination();
		m_CurrentNodeListTarget = (m_CurrentNodeListTarget + 1) % (m_NodeList.size());
		Goto(m_NodeList[m_CurrentNodeListTarget], FCNPC_MOVE_TYPE_WALK);
		return true;
	}
	bool OnUpdate() override
	{
		return true;
	}
public: //Timers
	
};

