#include "stdafx.h"
#include "PancakeWaiter.h"

using namespace QualificationRound;
using namespace std;

PancakeWaiter::PancakeWaiter(string pancakes) 
	: m_operationsCount{ 0 }, m_pancakes(pancakes.size())
{
	for (int i = 0; i < m_pancakes.size(); ++i)
	{
		m_pancakes[i] = pancakes[i] == '+';
	}
}

PancakeWaiter::~PancakeWaiter()
{
}

int PancakeWaiter::SortPancakes() noexcept
{
	// Potential algorithm:
	//	* ignore all the trailing +s
	//	* let N be the number of leading '-' and M the biggest series of '+' 
	//		* If N >= M flip all to transform them to '+'
	//		* Else flip twice to move the series of '+' on top the trailing + series

	while (!this->IsSorted())
	{
		int numberOfLeadingNonHappyFacePancakes = this->CalculateNumberOfLeadingNonHappyFacePancakes();
		int maxNumberOfHappyFacePancakesNotAtTheEnd = this->CalculateNumberOfNonSortedHappyFacePancakes();

		if (numberOfLeadingNonHappyFacePancakes >= maxNumberOfHappyFacePancakesNotAtTheEnd)
		{
			this->FlipAllNonSortedPancakes();
			++m_operationsCount;
		}
	}

	return m_operationsCount;
}

bool PancakeWaiter::IsSorted() const noexcept
{
	for (auto pancake : m_pancakes)
	{
		if (!pancake)
			return false;
	}

	return true;
}

int PancakeWaiter::CalculateNumberOfLeadingNonHappyFacePancakes() const noexcept
{
	auto firstHappyFace = find(m_pancakes.begin(), m_pancakes.end(), true);
	return firstHappyFace - m_pancakes.begin();
}

int PancakeWaiter::CalculateNumberOfNonSortedHappyFacePancakes() const noexcept
{
	int maxNumberOfHappyFacePancakesNotAtTheEnd = 0;
	int numberOfHappyFacePancakesNotAtTheEnd = 0;
	for (auto pancake : m_pancakes)
	{
		if (pancake)
		{
			++numberOfHappyFacePancakesNotAtTheEnd;
		}
		else
		{
			if (numberOfHappyFacePancakesNotAtTheEnd > maxNumberOfHappyFacePancakesNotAtTheEnd)
			{
				maxNumberOfHappyFacePancakesNotAtTheEnd = numberOfHappyFacePancakesNotAtTheEnd;
			}
			numberOfHappyFacePancakesNotAtTheEnd = 0;
		}
	}

	return maxNumberOfHappyFacePancakesNotAtTheEnd;
}

void PancakeWaiter::FlipAllNonSortedPancakes() noexcept
{
	auto lastPancakeNotSorted = (find(m_pancakes.rbegin(), m_pancakes.rend(), false) + 1).base();
	reverse(m_pancakes.begin(), lastPancakeNotSorted);
	for (auto it = m_pancakes.begin(); it != lastPancakeNotSorted + 1; ++it)
	{
		bool oldValue = *it;
		*it = !oldValue;
	}
}
