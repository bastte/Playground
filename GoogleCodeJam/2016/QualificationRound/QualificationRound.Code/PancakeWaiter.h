#pragma once

#include <string>
#include <vector>

#ifdef PANCAKEWAITER_EXPORTS
#define PANCAKEWAITER_API _declspec(dllexport)
#else
#define PANCAKEWAITER_API _declspec(dllimport)
#endif // PANCAKEWAITER_EXPORTS

namespace QualificationRound
{
	class PANCAKEWAITER_API PancakeWaiter
	{
	public:
		explicit PancakeWaiter(std::string pancakes);
		~PancakeWaiter();
		int SortPancakes() noexcept;

	private:
		bool IsSorted() const noexcept;

		int CalculateNumberOfLeadingNonHappyFacePancakes() const noexcept;
		std::pair<int, std::vector<bool>::iterator> CalculateNumberOfNonSortedHappyFacePancakes() noexcept;

		void FlipPancakes(std::vector<bool>::iterator pancakeToFlip);
		void FlipAllNonSortedPancakes() noexcept;

		std::vector<bool> m_pancakes;
		int m_operationsCount;
	};
}