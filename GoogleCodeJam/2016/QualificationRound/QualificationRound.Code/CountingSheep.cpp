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
	this->UpdateDigitsSeen();
}

CountingSheep::~CountingSheep()
{
}

void CountingSheep::CountOnce() noexcept
{
	if (this->IsAsleep())
	{
		return;
	}

	m_currentCount += m_number;
	this->UpdateDigitsSeen();
}

string CountingSheep::GetCount() const noexcept
{
	if (m_number == 0)
	{
		return "INSOMNIA";
	}
	
	return std::to_string(m_currentCount);
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

void CountingSheep::UpdateDigitsSeen() noexcept
{
	int temp = m_currentCount;
	while (temp > 0)
	{
		int lastDigit = temp % 10;
		m_digitsSeen[lastDigit] = true;
		temp /= 10;
	}
}
