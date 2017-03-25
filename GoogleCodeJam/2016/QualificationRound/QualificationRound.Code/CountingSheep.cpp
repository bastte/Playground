#include "stdafx.h"
#include "CountingSheep.h"

using namespace QualificationRound;

using namespace std;

CountingSheep::CountingSheep(int number) :
	m_number{ number },
	m_currentCount{ number },
	m_digitsSeen { false }
{
	// Update with digits from the initial number
	int temp = number;
	while (temp > 0)
	{
		int lastDigit = temp % 10;
		m_digitsSeen[lastDigit] = true;
		temp /= 10;
	}
}

CountingSheep::~CountingSheep()
{
}

void CountingSheep::CountOnce() noexcept
{
}

string CountingSheep::GetCount() const noexcept
{
	if (m_number == 0)
	{
		return "INSOMNIA";
	}

	return string{};
}

bool CountingSheep::IsAsleep() const noexcept
{
	for (int i = 0; i < 10; ++i)
	{
		if (!(m_digitsSeen[i]))
		{
			return false;
		}
	}
	return true;
}
