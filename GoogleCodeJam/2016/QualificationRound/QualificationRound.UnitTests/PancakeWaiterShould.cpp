#include "stdafx.h"
#include "CppUnitTest.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace QualificationRoundUnitTests
{
	TEST_CLASS(PancakeWaiterShould)
	{
	public:

		TEST_METHOD(NotDoAnythingIfPancakesAlreadySorted)
		{
			Assert::Fail();
		}

	};
}