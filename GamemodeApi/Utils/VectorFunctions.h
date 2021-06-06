#pragma once

#include <vector>

namespace Utils
{
	namespace Vector
	{
		template<class T>
		static std::vector<T> CreateVector(std::vector<T> input, size_t start = 0, size_t end = -1);

		template<class T>
		std::vector<T> CreateVector(std::vector<T> input, size_t start, size_t end)
		{
			typename std::vector<T>::const_iterator it_first = input.begin() + start;

			typename std::vector<T>::const_iterator it_end = ((end == -1 || end == input.size()) ? input.end() : input.begin() + end + 1);
			std::vector<T> result(it_first, it_end);
			return result;
		}
	}
}