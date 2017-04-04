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

		TEST_METHOD(SortAllPileInOneMove)
		{
			auto pancakeWaiter = PancakeWaiter{ "---" };
			Assert::AreEqual(1, pancakeWaiter.SortPancakes());
		}

		TEST_METHOD(SimpleSortInOneMove)
		{
			auto pancakeWaiter = PancakeWaiter{ "-+" };
			Assert::AreEqual(1, pancakeWaiter.SortPancakes());
		}

		TEST_METHOD(SimpleSortInTwoMoves)
		{
			auto pancakeWaiter = PancakeWaiter{ "+-" };
			Assert::AreEqual(2, pancakeWaiter.SortPancakes());
		}

		TEST_METHOD(SimpleSortInThreeMoves)
		{
			auto pancakeWaiter = PancakeWaiter{ "--+-" };
			Assert::AreEqual(3, pancakeWaiter.SortPancakes());
		}

	};
}