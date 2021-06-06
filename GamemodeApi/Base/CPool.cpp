#include "CPool.h"

std::unordered_map<int, CPlayer*> CPool::PlayerPool;
std::unordered_map<int, CNpc*> CPool::NpcPool;
bool CPool::PlayerExists(int id)
{
	return (CPool::PlayerPool.find(id) != CPool::PlayerPool.end());
}
CPlayer* CPool::GetPlayerFromId(int id)
{
	if (PlayerExists(id))
		return CPool::PlayerPool[id];
	return NULL;
}
void CPool::AllocatePlayer(int id)
{
	CPool::PlayerPool.insert(std::pair<int, CPlayer*>(id, new CPlayer(id)));
}
void CPool::DeallocatePlayer(int id)
{
	if (PlayerExists(id))
	{
		delete CPool::PlayerPool[id];
		CPool::PlayerPool.erase(id);
	}
}
void CPool::DeallocatePlayerList()
{
	for (std::unordered_map<int, CPlayer*>::iterator it = CPool::PlayerPool.begin(); it != CPool::PlayerPool.end(); it++) {
		delete it->second;
	}
}