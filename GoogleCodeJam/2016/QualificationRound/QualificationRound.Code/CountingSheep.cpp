#include "stdafx.h"
#include "CountingSheep.h"

using namespace QualificationRound;

using namespace std;

CountingSheep::CountingSheep(int number) :
	m_number{ number },
	m_currentCount{ number }
{
	m_digitsSeen = unordered_map<int, bool>{};
	for (int i = 0; i < 10; ++i)
	{
		m_digitsSeen[i] = false;
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
	return false;
}
