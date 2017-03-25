#pragma once

#include <string>
#include <unordered_map>

#ifdef COUNTINGSHEEP_EXPORTS
#define COUNTINGSHEEP_API _declspec(dllexport)
#else
#define COUNTINGSHEEP_API _declspec(dllimport)
#endif // COUNTINGSHEEP_EXPORTS

namespace QualificationRound
{
	class COUNTINGSHEEP_API CountingSheep
	{
	public:
		explicit CountingSheep(int number = 0);
		~CountingSheep();

		void CountOnce() noexcept;
		std::string GetCount() const noexcept;
		bool IsAsleep() const noexcept;

	private:
		int m_number;
		int m_currentCount; // TODO: long long ?
		std::unordered_map<int, bool> m_digitsSeen;
	};
}