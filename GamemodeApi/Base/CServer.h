#pragma once
#ifndef CSERVER_INCLUDED
#define CSERVER_INCLUDED

#include <vector>

#include <sampgdk/sampgdk.h>

#include "Macros/DebugMacros.h"
namespace CServer
{
	static std::vector<int> ExclusionList;
	static void UsePedAnims();
	template<typename T, typename... Types>
	static void AddDefaultPedClasses(T var, Types... list);
	static void AddDefaultPedClasses();

	void UsePedAnims()
	{
		LOGPRINTF_DEBUG_CLASS(__FUNCTION__, NULL, "");
		UsePlayerPedAnims();
	}
	template<typename T, typename... Types>
	void AddDefaultPedClasses(T var, Types... list)
	{
		CServer::ExclusionList.push_back(var);
		CServer::AddDefaultPedClasses(list...);
	}
	void AddDefaultPedClasses()
	{
		for (int i = 0; i < 311; i++)
		{
			if (std::find(ExclusionList.begin(), ExclusionList.end(), i) == ExclusionList.end())
				AddPlayerClass(i, 0.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0);
		}
	}
}

#endif