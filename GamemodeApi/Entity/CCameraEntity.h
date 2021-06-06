#pragma once

#include "CBaseEntity.h"

class CCameraEntity : protected CBaseEntity
{
public:
	CCameraEntity();
	void SetLookAt(CVector3f LookAt);

	void SetPosition(CVector3f Position) override
	{
		SetPlayerCameraPos(m_ID, Position.x, Position.y, Position.z);
	}
	CVector3f GetPosition() override
	{
		GetPlayerCameraPos(m_ID, &m_Position->x, &m_Position->y, &m_Position->z);
		return *m_Position;
	}
	virtual ~CCameraEntity();
};

