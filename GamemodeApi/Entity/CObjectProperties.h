#pragma once

#include <string>
#include <unordered_map>

class CObjectProperties
{
private:
	std::unordered_map<std::string, void*> m_PropertyMap;
public:
	CObjectProperties();
	void SetProperty(const std::string& key, void* value);
	void* GetProperty(const std::string& key);
	void Empty();
	virtual ~CObjectProperties();
};

