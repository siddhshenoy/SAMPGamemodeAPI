#include "CCameraEntity.h"

CCameraEntity::CCameraEntity() : CBaseEntity(true, false, false)
{

}

void CCameraEntity::SetLookAt(CVector3f LookAt)
{
	SetPlayerCameraLookAt(m_ID, LookAt.x, LookAt.y, LookAt.z, CAMERA_CUT);
}
CCameraEntity::~CCameraEntity()
{

}