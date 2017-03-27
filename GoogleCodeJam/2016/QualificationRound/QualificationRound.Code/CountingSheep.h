#pragma once

#include <string>
#include <array>

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

		void CountOnce() noexcept;
		std::string GetCount() const noexcept;
		bool IsAsleep() const noexcept;

	private:
		void UpdateDigitsSeen() noexcept;

		int m_number;
		int m_currentCount;
		std::array<bool, 10> m_digitsSeen;
	};
}