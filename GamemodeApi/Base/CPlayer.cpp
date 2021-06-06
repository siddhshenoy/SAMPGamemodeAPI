#include "CPlayer.h"

CPlayer::CPlayer()
{
	//LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "");
	//SetEntityType(CEntityType::ENTITY_PLAYER);
	//Camera = std::unique_ptr<CCamera>(new CCamera());
	Camera = new CCamera();
}
CPlayer::CPlayer(int id)
{
	//LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "");
	//SetEntityType(CEntityType::ENTITY_PLAYER);
	SetID(id);
	Camera = new CCamera(GetID());
	//Camera = std::unique_ptr<CCamera>(new CCamera(GetID()));
}
CPlayer::~CPlayer()
{
	//LOGPRINTF_DEBUG_CLASS(__FUNCTION__, this, "");
	delete Camera;
}