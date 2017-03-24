#include "stdafx.h"
#include "CppUnitTest.h"
#include "../QualificationRound.Code/CountingSheep.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace QualificationRound;

namespace QualificationRoundUnitTests
{		
	TEST_CLASS(CountingSheepShould)
	{
	public:
		
		TEST_METHOD(ReturnInsomniaForZero)
		{
			auto countingSheep = CountingSheep{ 0 };
			Assert::Fail();
		}

	};
}