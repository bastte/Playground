#include "stdafx.h"
#include "PancakeWaiter.h"
#include <iostream>

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
		this->PrintPancakes();

		int numberOfLeadingNonHappyFacePancakes = this->CalculateNumberOfLeadingNonHappyFacePancakes();
		auto biggestHappyFacePancakesNotAtEnd = this->CalculateNumberOfNonSortedHappyFacePancakes();

		if (numberOfLeadingNonHappyFacePancakes >= biggestHappyFacePancakesNotAtEnd.first)
		{
			this->FlipAllNonSortedPancakes();
			++m_operationsCount;
		}
		else
		{
			this->FlipPancakes(biggestHappyFacePancakesNotAtEnd.second);
			++m_operationsCount;

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

void PancakeWaiter::PrintPancakes() const noexcept
{
	for (auto pancake : m_pancakes)
	{
		cout << pancake ? '+' : '-';
	}

	cout << endl;
}

int PancakeWaiter::CalculateNumberOfLeadingNonHappyFacePancakes() const noexcept
{
	auto firstHappyFace = find(m_pancakes.begin(), m_pancakes.end(), true);
	return firstHappyFace - m_pancakes.begin();
}

pair<int, vector<bool>::iterator> PancakeWaiter::CalculateNumberOfNonSortedHappyFacePancakes() noexcept
{
	int maxNumberOfHappyFacePancakesNotAtTheEnd = 0;
	int numberOfHappyFacePancakesNotAtTheEnd = 0;
	auto flippingPosition = m_pancakes.begin();
	for (auto it = m_pancakes.begin(); it != m_pancakes.end(); ++it)
	{
		if (*it)
		{
			++numberOfHappyFacePancakesNotAtTheEnd;
		}
		else
		{
			if (numberOfHappyFacePancakesNotAtTheEnd > maxNumberOfHappyFacePancakesNotAtTheEnd)
			{
				maxNumberOfHappyFacePancakesNotAtTheEnd = numberOfHappyFacePancakesNotAtTheEnd;
				flippingPosition = it;
			}
			numberOfHappyFacePancakesNotAtTheEnd = 0;
		}
	}

	return make_pair(maxNumberOfHappyFacePancakesNotAtTheEnd, flippingPosition);
}

void PancakeWaiter::FlipAllNonSortedPancakes() noexcept
{
	auto lastPancakeNotSorted = (find(m_pancakes.rbegin(), m_pancakes.rend(), false) + 1).base();
	this->FlipPancakes(lastPancakeNotSorted);
}

void PancakeWaiter::FlipPancakes(std::vector<bool>::iterator pancakeToFlip)
{
	reverse(m_pancakes.begin(), pancakeToFlip);
	for (auto it = m_pancakes.begin(); it != pancakeToFlip + 1; ++it)
	{
		bool oldValue = *it;
		*it = !oldValue;
	}
}
