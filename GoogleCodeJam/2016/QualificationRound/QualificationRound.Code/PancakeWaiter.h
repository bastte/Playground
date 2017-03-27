#pragma once

#include <string>

#ifdef PANCAKEWAITER_EXPORTS
#define PANCAKEWAITER_API _declspec(dllexport)
#else
#define PANCAKEWAITER_API _declspec(dllimport)
#endif // PANCAKEWAITER_EXPORTS

namespace QualificationRound
{
	class PANCAKEWAITER_API PancakeWaiter
	{
	public:
		explicit PancakeWaiter(std::string pancakes);
		int SortPancakes() noexcept;
	};
}