#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	class BGSActionData;

	class BGSAnimationSequencer
	{
	public:
		// members
		std::uint32_t                             numSequences;  // 00
		std::uint32_t                             pad04;         // 04
#ifndef SUPPORT_SKYRIM_AE
		BSTHashMap<BSFixedString, BGSActionData*> actions;       // 08
#else
		BSTFixedHashMap<BSFixedString, BGSActionData*> actions;  // 08 - _sentinel is at 0x10 on AE but unsure for 1.5.x
#endif
	};
	static_assert(sizeof(BGSAnimationSequencer) == 0x38);
}
