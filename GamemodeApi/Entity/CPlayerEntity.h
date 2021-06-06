#pragma once



#include "Entity/CBaseEntity.h"
#include "Entity/CObjectProperties.h"

class CPlayerEntity : public CBaseEntity, public CObjectProperties
{
public:
	CPlayerEntity();

	void SetPosition(CVector3f Position) override
	{
		SetPlayerPos(m_ID, Position.x, Position.y, Position.z);
	}
	CVector3f GetPosition() override
	{
		GetPlayerPos(m_ID, &m_Position->x, &m_Position->y, &m_Position->z);
		sampgdk::logprintf("%f", m_Position->x);
		return *m_Position;
	}
	float GetRotationZ() override
	{
		GetPlayerFacingAngle(m_ID, &m_Rotation->z);
		return m_Rotation->z;
	}
	void SetRotationZ(float Rotation)  override
	{
		SetPlayerFacingAngle(m_ID, Rotation);
	}

	virtual ~CPlayerEntity();
};
