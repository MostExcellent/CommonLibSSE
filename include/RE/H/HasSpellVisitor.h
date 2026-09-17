#pragma once

#include "RE/A/Actor.h"

namespace RE
{
	class HasSpellVisitor : Actor::ForEachSpellVisitor
	{
	public:
		inline static constexpr auto RTTI = RTTI_HasSpellVisitor;
		inline static constexpr auto VTABLE = VTABLE_HasSpellVisitor;

		HasSpellVisitor(const HasSpellVisitor&) = default;
		HasSpellVisitor& operator=(const HasSpellVisitor&) = default;
		HasSpellVisitor(HasSpellVisitor&&) = default;
		HasSpellVisitor& operator=(HasSpellVisitor&&) = default;

		~HasSpellVisitor() override = default;  // 00

		// override (Actor::ForEachSpellVisitor)
		BSContainer::ForEachResult Visit(SpellItem* a_spell) override;  // 01

		// members
		SpellItem* spell;   // 08
		bool       found;   // 10
	};
	static_assert(sizeof(HasSpellVisitor) == 0x18);
}
