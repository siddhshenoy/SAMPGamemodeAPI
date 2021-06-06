#pragma once

#include <string>
#include <vector>

namespace Utils
{
	namespace String
	{
		static std::vector<std::string> Split(const std::string& str, const char delimiter = ' ');
		static std::vector<std::string> Split(const char* string, const char delimiter = ' ');
		static char** Split(const std::string& str, unsigned int& total, const char delimiter = ' ');
		static char** Split(const char* string, unsigned int& total, const char delimiter = ' ');
		//static std::string strreplace(const std::string& str,const std::string& toreplace,const std::string& replacestr);

		static bool IsInt(const std::string& str);
		static bool IsFloat(const std::string& str);
		static int ToInt(const std::string& str);
		static float ToFloat(const std::string& str);

		std::vector<std::string> Split(const std::string& str, const char delimiter)
		{
			std::vector<std::string> results; // Main vector array in which we will store the results
			std::vector<unsigned int> delimpos; //A vector which will search for all the delimiter positions and put it in an array
			std::string tempString; // Temp string to put the substr in that
			unsigned int lastpos = 0; // Last Delimiter position

			for (unsigned int i = 0; i < str.length(); i++)
				if (str[i] == delimiter)
					delimpos.push_back(i);

			delimpos.push_back(str.length());

			for (unsigned int i = 0; i < delimpos.size(); i++)
			{
				tempString = str.substr(lastpos, delimpos[i] - lastpos);
				results.push_back(tempString);
				lastpos = delimpos[i] + 1;
			}
			return results;
		}
		std::vector<std::string> Split(const char* string, const char delimiter)
		{
			return Split(std::string(string), delimiter);
		}
		char** Split(const std::string& str, unsigned int& total, const char delimiter)
		{
			char** result;
			std::vector<std::string> tempRes;
			tempRes = Split(str, delimiter);
			result = new char* [tempRes.size()];
			for (unsigned int i = 0; i < tempRes.size(); i++)
			{
				result[i] = new char[tempRes[i].length() + 1];
				//result[i] = (char*)tempRes[i].c_str();
				memcpy(result[i], tempRes[i].c_str(), tempRes[i].length());
				result[i][tempRes[i].length()] = '\0';
			}
			total = tempRes.size();
			tempRes.clear();
			return result;
		}
		char** Split(const char* string, unsigned int& total, const char delimiter)
		{
			return Split(std::string(string), total, delimiter);
		}
		bool IsInt(const std::string& str)
		{
			bool res = false;
			for (unsigned int i = 0; i < str.length(); i++)
			{
				if (str[i] >= '0' && str[i] <= '9')
				{
					res = true;
					continue;
				}
				else
				{
					res = false;
					break;
				}
			}
			return res;
		}
		bool IsFloat(const std::string& str)
		{
			bool hasnumbers = false;
			bool hasdecimal = false;
			for (unsigned int i = 0; i < str.length(); i++)
			{
				if (str[i] == '.')
				{
					if (!hasdecimal) {
						hasdecimal = true;
						continue;
					}
					else {
						hasdecimal = false;
						break;
					}
				}

				if (str[i] >= '0' && str[i] <= '9')
				{
					hasnumbers = true;
					continue;
				}
				else
				{
					hasnumbers = false;
					break;
				}
			}
			return (hasdecimal && hasnumbers);
		}
		int ToInt(const std::string& str)
		{
			return std::atoi(str.c_str());
		}
		float ToFloat(const std::string& str)
		{
			return (float)std::atof(str.c_str());
		}
	}
};



