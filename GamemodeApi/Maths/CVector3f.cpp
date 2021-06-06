#include "CVector3f.h"

CVector3f::CVector3f()
{
	x = y = z = 0.0f;
}
CVector3f::CVector3f(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
void CVector3f::setX(float x)
{
	this->x = x;
}
void CVector3f::setY(float y)
{
	this->y = y;
}
void CVector3f::setZ(float z)
{
	this->z = z;
}
float CVector3f::getX()
{
	return x;
}
float CVector3f::getY()
{
	return y;
}
float CVector3f::getZ()
{
	return z;
}
float CVector3f::magnitude()
{
	float length = 0.0f;
	length = (float)sqrt(pow(x, 2.0f) + pow(y, 2.0f) + pow(z, 2.0f));
	return length;
}
float CVector3f::DistanceXY(CVector3f other)
{
	float distance = 0.0f;
	float diffX = x - other.getX();
	float diffY = y - other.getY();
	distance = (float)sqrt(pow(diffX, 2.0f) + pow(diffY, 2.0f));
	return distance;
}
float CVector3f::Distance(CVector3f other)
{
	float distance = 0.0f;
	float diffX = x - other.getX();
	float diffY = y - other.getY();
	float diffZ = z - other.getZ();
	distance = (float)sqrt(pow(diffX, 2.0f) + pow(diffY, 2.0f) + pow(diffZ, 2.0f));
	return distance;
}
CVector3f CVector3f::operator+(CVector3f other)
{
	CVector3f result;
	result.x = x + other.x;
	result.y = y + other.y;
	result.z = z + other.z;
	return result;
}
CVector3f CVector3f::operator/(float scalar)
{
	CVector3f result;
	result.x = x / scalar;
	result.y = y / scalar;
	result.z = z / scalar;
	return result;
}
CVector3f CVector3f::operator-(CVector3f other)
{
	CVector3f result;
	result.x = x - other.x;
	result.y = y - other.y;
	result.z = z - other.z;
	return result;
}
CVector3f CVector3f::normalize()
{
	CVector3f result;
	float mag = magnitude();
	result.x = x / mag;
	result.y = y / mag;
	result.z = z / mag;
	return result;
}
CVector3f CVector3f::operator*(float scalar)
{
	CVector3f result;
	result.x = x * scalar;
	result.y = y * scalar;
	result.z = z * scalar;
	return result;
}
CVector3f::~CVector3f()
{

}