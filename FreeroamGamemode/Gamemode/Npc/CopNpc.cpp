#include "CopNpc.h"

CopNpc::CopNpc()
{
	m_LastUpdateTime = -1;
}
void CopNpc::LoadNodeList(const std::string& NodeListPath)
{
	std::string line;
	std::fstream nodefile;
	nodefile.open(NodeListPath.c_str(), std::fstream::in);
	if (nodefile.good())
	{
		sampgdk::logprintf("[CopNpc LOAD]: Loading nodelist from file '%s'", NodeListPath.c_str());
		while (!nodefile.eof())
		{
			std::getline(nodefile, line);
			std::vector<std::string> splits = Split(line, ',');
			if (splits.size() == 3)
			{
				CVector3f Position;
				Position.x = ToFloat(splits[0]);
				Position.y = ToFloat(splits[1]);
				Position.z = ToFloat(splits[2]);
				m_NodeList.push_back(Position);
				sampgdk::logprintf("Pushing the vector(%f, %f, %f)", Position.x, Position.y, Position.z);
			}
			else
			{
				sampgdk::logprintf("[CopNpc READ ERROR]: The line '%s' has insufficient/excess amount of delimiters", line.c_str());
			}
		}
		sampgdk::logprintf("[CopNpc DEBUG]: Node List loading for CopNpc finished..");
		sampgdk::logprintf("[CopNpc DEBUG]: Total nodes loaded: %d", m_NodeList.size());
	}
	else
	{
		sampgdk::logprintf("[CopNpc ERROR]: Error while loading node-list from file '%s'. The specified path does not exist!", NodeListPath.c_str());
	}
	nodefile.close();
}
CopNpc::~CopNpc()
{

}

//Timers

