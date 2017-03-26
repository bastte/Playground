#include "stdafx.h"
#include "CppUnitTest.h"
#include "../QualificationRound.Code/CountingSheep.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace QualificationRound;
using namespace std;

namespace QualificationRoundUnitTests
{
	TEST_CLASS(CountingSheepShould)
	{
	public:

		TEST_METHOD(ReturnInsomniaForZero)
		{
			auto countingSheep = CountingSheep{ 0 };
			countingSheep.CountOnce();
			string expectedCount = "INSOMNIA";
			Assert::AreEqual(expectedCount, countingSheep.GetCount());
		}

		TEST_METHOD(NotSleepInitially)
		{
			auto countingSheep = CountingSheep{ 1 };
			Assert::IsFalse(countingSheep.IsAsleep());
		}

		TEST_METHOD(SleepImmediatelyIfNumberContainsAllDigits)
		{
			auto countingSheep = CountingSheep{ 1234567890 };
			Assert::IsTrue(countingSheep.IsAsleep());
		}

		TEST_METHOD(ReturnInitialNumberIfSleepingImmediately)
		{
			auto countingSheep = CountingSheep{ 1234567890 };
			string expectedCount = "1234567890";
			Assert::AreEqual(expectedCount, countingSheep.GetCount());
		}

		TEST_METHOD(StopCountingWhenAsleep)
		{
			auto countingSheep = CountingSheep{ 1 };
			for (int i = 0; i < 10; ++i)
			{
				countingSheep.CountOnce();
			}

			Assert::IsTrue(countingSheep.IsAsleep());
			auto currentCount = countingSheep.GetCount();
			countingSheep.CountOnce();
			Assert::AreEqual(currentCount, countingSheep.GetCount());
		}

	};
}