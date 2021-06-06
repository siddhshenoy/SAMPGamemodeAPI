#pragma once

#include <math.h>

#define CVECTOR3_PUBLIC

class CVector3f
{
#ifdef CVECTOR3_PUBLIC
public:
	float x;
	float y;
	float z;
#else
private:
	float x;
	float y;
	float z;
#endif
public:
	CVector3f();
	CVector3f(float x, float y, float z);
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	float getX();
	float getY();
	float getZ();
	float magnitude();
	CVector3f normalize();
	CVector3f operator+(CVector3f other);
	CVector3f operator/(float scalar);
	CVector3f operator-(CVector3f other);
	CVector3f operator*(float scalar);
	//CVector3f operator/=(float scalar);
	float DistanceXY(CVector3f other);
	float Distance(CVector3f other);
	~CVector3f();

};

