#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class TESIdleForm;

	class ActionOutput
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActionOutput;

		enum class Result
		{
			kNotAllowed = -1,
			kNone = 0,
			kNormal = 1,
			kNoAnimationEvent = 2,
		};

		// members
		BSFixedString         animEvent;             // 00
		BSFixedString         targetAnimEvent;       // 08
		REX::TEnumSet<Result, std::int32_t> result;  // 10
		TESIdleForm*          sequence;              // 18
		const TESIdleForm*    animObjIdle;           // 20
		uint32_t              sequenceIndex;         // 28
	};
	static_assert(sizeof(ActionOutput) == 0x30);
}
