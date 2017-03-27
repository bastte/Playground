#include "stdafx.h"
#include "PancakeWaiter.h"

using namespace QualificationRound;
using namespace std;

// Potential algorithm:
//	* ignore all the trailing +s
//	* let N be the number of leading '-' and M the biggest series of '+' 
//		* If N >= M flip all to transform them to '+'
//		* Else flip twice to move the series of '+' on top the trailing + series

PancakeWaiter::PancakeWaiter(string pancakes)
{
}

int PancakeWaiter::SortPancakes() noexcept
{
	return 0;
}
