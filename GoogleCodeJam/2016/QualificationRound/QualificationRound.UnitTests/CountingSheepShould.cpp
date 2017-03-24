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
			Assert::AreEqual(string{ "INSOMNIA" }, countingSheep.GetCount());
		}

	};
}