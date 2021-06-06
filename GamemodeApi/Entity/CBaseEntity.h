#pragma once

#include <memory>
#include <unordered_map>
#include <sampgdk/sampgdk.h>
#include "Maths/CVector3f.h"

class CBaseEntity
{
protected:
	int m_ID;
	//CVector3f m_Position;
	//CVector3f m_Rotation;
	std::unique_ptr<CVector3f> m_Position;
	std::unique_ptr<CVector3f> m_Rotation;
	std::unique_ptr<int> m_Model;
	std::unordered_map<std::string, void*> m_VariableMap;
public:
	void SetID(int);
	int GetID();

	virtual void SetPosition(CVector3f Position) { }
	virtual void SetRotation(CVector3f Rotation) { }
	virtual void SetRotationZ(float) { }
	virtual void SetModel(int) { }

	virtual CVector3f GetPosition() { return CVector3f(); }
	virtual CVector3f GetRotation() { return CVector3f(); }
	virtual float GetRotationZ() { return 0.0f; }
	virtual int GetModel() { return -1; }

public:
	CBaseEntity();
	//CBaseEntity(int TotalRotations);
	CBaseEntity(bool HasPosition, bool HasRotation, bool HasModel);
	virtual ~CBaseEntity();
};