#include "stdafx.h"
#include "CppUnitTest.h"
#include "../QualificationRound.Code/PancakeWaiter.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace QualificationRound;
using namespace std;

namespace QualificationRoundUnitTests
{
	TEST_CLASS(PancakeWaiterShould)
	{
	public:

		TEST_METHOD(NotDoAnythingIfPancakesAlreadySorted)
		{
			auto pancakeWaiter = PancakeWaiter{ "+++++" };
			Assert::AreEqual(0, pancakeWaiter.SortPancakes());
		}

	};
}