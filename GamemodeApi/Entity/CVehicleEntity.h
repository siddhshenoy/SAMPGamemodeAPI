#pragma once

#include "CBaseEntity.h"

class CVehicleEntity : protected CBaseEntity
{

public:
	CVehicleEntity();
	void SetPosition(CVector3f Position) override
	{
		SetVehiclePos(m_ID, Position.x, Position.y, Position.z);
	}
	CVector3f GetPosition() override
	{
		GetVehiclePos(m_ID, &(m_Position->x), &(m_Position->y), &(m_Position->z));
		return *m_Position;
	}
	void SetRotationZ(float Rotation) override
	{
		SetVehicleZAngle(m_ID, Rotation);
	}
	float GetRotationZ() override
	{
		GetVehicleZAngle(m_ID, &m_Rotation->z);
		return m_Rotation->z;
	}
	virtual ~CVehicleEntity();
};

