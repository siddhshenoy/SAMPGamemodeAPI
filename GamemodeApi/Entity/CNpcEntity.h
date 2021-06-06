#pragma once

#include "Plugins/FCNPC.h"
#include "CBaseEntity.h"

class CNpcEntity : protected CBaseEntity
{
public:
	CNpcEntity();
	void SetPosition(CVector3f Position) override
	{
		Plugins::FCNPC::SetPosition(m_ID, Position.x, Position.y, Position.z);
	}
	CVector3f GetPosition() override
	{
		Plugins::FCNPC::GetPosition(m_ID, &(m_Position->x), &(m_Position->y), &(m_Position->z));
		return *m_Position;
	}
	void SetModel(int Model)
	{
		*m_Model = Model;
	}
	int GetModel() override
	{
		return *m_Model;
	}
	virtual ~CNpcEntity();
};

