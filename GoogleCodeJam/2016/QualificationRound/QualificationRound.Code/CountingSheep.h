#pragma once

#include <string>

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
	};
}