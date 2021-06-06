#include "CBaseEntity.h"

CBaseEntity::CBaseEntity()
{
	m_ID = -1;

}
CBaseEntity::CBaseEntity(bool HasPosition, bool HasRotation, bool HasModel)
{
	m_ID = -1;
	if (HasPosition) {
		m_Position = std::unique_ptr<CVector3f>(new CVector3f());
	}
	if (HasRotation) {
		m_Rotation = std::unique_ptr<CVector3f>(new CVector3f());
	}
	if (HasModel) {
		m_Model = std::unique_ptr<int>(new int(1));
	}
}
void CBaseEntity::SetID(int id)
{
	m_ID = id;
}
int CBaseEntity::GetID()
{
	return m_ID;
}
CBaseEntity::~CBaseEntity()
{

}