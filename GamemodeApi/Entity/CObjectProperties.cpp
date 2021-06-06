#include "CObjectProperties.h"

CObjectProperties::CObjectProperties()
{

}
void CObjectProperties::SetProperty(const std::string& key, void* value)
{
	if (m_PropertyMap.find(key) != m_PropertyMap.end())
	{
		m_PropertyMap[key] = value;
	}
	else
	{
		m_PropertyMap.insert(std::pair<std::string, void*>(key, value));
	}
}
void* CObjectProperties::GetProperty(const std::string& key)
{
	if (m_PropertyMap.find(key) != m_PropertyMap.end())
	{
		return m_PropertyMap[key];
	}
	return NULL;
}
void CObjectProperties::Empty()
{
	for (std::unordered_map<std::string, void*>::iterator i = m_PropertyMap.begin(); i != m_PropertyMap.end(); i++)
	{
		m_PropertyMap.erase(i->first);
	}
}
CObjectProperties::~CObjectProperties()
{
	Empty();
}