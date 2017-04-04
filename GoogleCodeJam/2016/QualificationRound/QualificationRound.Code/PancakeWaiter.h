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
		int CalculateNumberOfNonSortedHappyFacePancakes() const noexcept;
		void FlipAllNonSortedPancakes() noexcept;
		void FlipPancakes(std::vector<bool>::iterator pancakeToFlip);
		void FlipBiggestHappyFaceSequence() noexcept;

		std::vector<bool> m_pancakes;
		int m_operationsCount;
	};
}