#include "CPlayerEntity.h"

CPlayerEntity::CPlayerEntity() : CBaseEntity(true, true, true)
{

}
/*
void CPlayerEntity::SetPosition(CVector3f Position)
{
	SetPlayerPos(m_ID, Position.x, Position.y, Position.z);
}
CVector3f CPlayerEntity::GetPosition()
{
	GetPlayerPos(m_ID, &m_Position.x, &m_Position.y, &m_Position.z);
	return m_Position;
}
float CPlayerEntity::GetRotation()
{
	GetPlayerFacingAngle(m_ID, &m_Rotation[0]);
	return m_Rotation[0];
}
void CPlayerEntity::SetRotation(float Rotation)
{
	SetPlayerFacingAngle(m_ID, Rotation);
}
*/
CPlayerEntity::~CPlayerEntity()
{

}