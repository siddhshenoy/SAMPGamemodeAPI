#pragma once

#include "CEntityType.h"

#include "Macros/DebugMacros.h"
#include "Maths/CVector3f.h"

class CEntity
{
protected:
	CEntityType m_EntityType;
	CVector3f m_Position;
	CVector3f m_Rotation;
	int m_Model;
	int m_ID;
public:
	CEntity();

	void SetID(int id);
	int GetID();

	void SetEntityType(CEntityType Type);
	CEntityType GetEntityType();

	void SetPosition(float x, float y, float z);
	void GetPosition(float* x, float* y, float* z);

	void SetPosition(CVector3f Position);
	CVector3f GetPosition();

	void SetModel(int Model);
	int GetModel();

	void SetRotation(CVector3f Rotation);
	CVector3f GetRotation();

	void SetLookAt(CVector3f Position, int Cut = CAMERA_CUT);
	CVector3f GetLookAt();

	virtual ~CEntity();
};

