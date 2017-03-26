#include "stdafx.h"
#include "CppUnitTest.h"
#include "../QualificationRound.Code/CountingSheep.h"
#include <fstream>

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

		TEST_METHOD(ReturnCorrectCountAfterAFewRounds)
		{
			auto countingSheep = CountingSheep{ 1692 };
			Assert::IsFalse(countingSheep.IsAsleep());
			countingSheep.CountOnce();
			Assert::IsFalse(countingSheep.IsAsleep());
			countingSheep.CountOnce();
			Assert::IsTrue(countingSheep.IsAsleep());
			string expectedCount = "5076";
			Assert::AreEqual(expectedCount, countingSheep.GetCount());
		}

		TEST_METHOD(SolveSmallInput)
		{
			this->SolveTestCase("A-small-practice");
		}

		TEST_METHOD(SolveLargeInput)
		{
			this->SolveTestCase("A-large-practice");
		}

	private:
		void SolveTestCase(string inputName)
		{
			ifstream inputFile{ "Input/" + inputName + ".in", ifstream::in };
			ofstream outputFile{ inputName + ".out", ofstream::trunc };

			int initialNumber;
			int caseNumber{ 0 };

			while (inputFile >> initialNumber)
			{
				auto sheep = CountingSheep{ initialNumber };
				while (!sheep.IsAsleep())
				{
					if (sheep.GetCount() == "INSOMNIA")
					{
						break;
					}

					sheep.CountOnce();
				}

				auto lastNumberSeen = sheep.GetCount();
				outputFile << "Case #" << ++caseNumber << ": " << lastNumberSeen << endl;
			}

			inputFile.close();
			outputFile.close();
		}

	};
}