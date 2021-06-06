#include "CEntity.h"

CEntity::CEntity()
{
	m_ID = -1;
	m_Model = -1;
	m_Position = CVector3f(0.0f, 0.0f, 0.0f);
	m_Rotation = CVector3f(0.0f, 0.0f, 0.0f);
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "");
}

void CEntity::SetEntityType(CEntityType Type)
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "ENTITY (%d)", Type);
	m_EntityType = Type;
}
CEntityType CEntity::GetEntityType()
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "");
	return m_EntityType;
}

void CEntity::SetID(int id)
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "ID %d", id);
	m_ID = id;
}
int CEntity::GetID()
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "");
	return m_ID;
}

void CEntity::SetPosition(float x, float y, float z)
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "FLOAT (%f, %f, %f)", x, y, z);
	switch (m_EntityType)
	{
		case CEntityType::ENTITY_PLAYER:
		{
			SetPlayerPos(m_ID, x, y, z);
			break;
		}
		case CEntityType::ENTITY_CAMERA:
		{
			SetPlayerCameraPos(m_ID, x, y, z);
			break;
		}
	}
}
void CEntity::GetPosition(float* x, float* y, float* z)
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "FLOAT");
	switch (m_EntityType)
	{
		case CEntityType::ENTITY_PLAYER:
		{
			GetPlayerPos(m_ID, x, y, z);
			break;
		}
		case CEntityType::ENTITY_CAMERA:
		{
			GetPlayerCameraPos(m_ID, x, y, z);
			break;
		}
	}
}

void CEntity::SetPosition(CVector3f Position)
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "VECTOR (%f, %f, %f)", Position.x, Position.y, Position.z);
	switch (m_EntityType)
	{
		case CEntityType::ENTITY_PLAYER:
		{
			SetPlayerPos(m_ID, Position.x, Position.y, Position.z);
			break;
		}
		case CEntityType::ENTITY_CAMERA:
		{
			SetPlayerCameraPos(m_ID, Position.x, Position.y, Position.z);
			break;
		}
	}
}
CVector3f CEntity::GetPosition()
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "VECTOR(%d)", GetEntityType());
	switch (m_EntityType)
	{
		case CEntityType::ENTITY_PLAYER:
		{
			GetPlayerPos(m_ID, &m_Position.x, &m_Position.y, &m_Position.z);
			break;
		}
		case CEntityType::ENTITY_CAMERA:
		{
			GetPlayerCameraPos(m_ID, &m_Position.x, &m_Position.y, &m_Position.z);
			break;
		}
	}
	return m_Position;
}
void CEntity::SetModel(int Model)
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "MODEL (%d)", Model);
	switch (m_EntityType)
	{
		case CEntityType::ENTITY_PLAYER:
		{
			SetPlayerSkin(m_ID, Model);
			break;
		}
	}
}
int CEntity::GetModel()
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "");
	switch (m_EntityType)
	{
		case CEntityType::ENTITY_PLAYER:
		{
			m_Model =  GetPlayerSkin(m_ID);
			break;
		}
	}
	return m_Model;
}

void CEntity::SetRotation(CVector3f Rotation)
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, " VECTOR(%f, %f, %f)", Rotation.x, Rotation.y, Rotation.z);
	switch (m_EntityType)
	{
		case CEntityType::ENTITY_PLAYER:
		{
			SetPlayerFacingAngle(m_ID, Rotation.z);
			break;
		}
	}
}
CVector3f CEntity::GetRotation()
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "");
	switch (m_EntityType)
	{
		case CEntityType::ENTITY_PLAYER:
		{
			m_Rotation.x = 0.0f;
			m_Rotation.y = 0.0f;
			GetPlayerFacingAngle(m_ID, &m_Rotation.z);
			break;
		}
	}
	return m_Rotation;
}

void CEntity::SetLookAt(CVector3f Position, int Cut)
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, " VECTOR (%f, %f, %f)", Position.x, Position.y, Position.z);
	switch (m_EntityType)
	{
		case CEntityType::ENTITY_CAMERA:
		{
			SetPlayerCameraLookAt(m_ID, Position.x, Position.y, Position.z, Cut);
			break;
		}
	}
}
CVector3f CEntity::GetLookAt()
{
	return CVector3f(0.0f, 0.0f, 0.0f);
}
CEntity::~CEntity()
{
	LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "");
}