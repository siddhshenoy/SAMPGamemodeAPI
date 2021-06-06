#pragma once

#include <memory>
//#include "CEntity.h"
#include "Entity/CPlayerEntity.h"
#include "CCamera.h"



class CPlayer : public CPlayerEntity
{
public:
	//std::unique_ptr<CCamera> Camera;
	CCamera* Camera;
public:
	CPlayer();
	CPlayer(int id);
	~CPlayer();
};

