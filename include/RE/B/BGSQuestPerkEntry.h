#pragma once
#include "BGSPerkEntry.h"


namespace RE
{
	struct QuestPerkEntryData
	{
		QuestPerkEntryData() = default;

		TESQuest* quest;           // 00
		std::uint16_t questStage;  // 08
	};
	static_assert(sizeof(QuestPerkEntryData) == 0x10);

	class BGSQuestPerkEntry : public BGSPerkEntry
	{
		inline static constexpr auto RTTI = RTTI_BGSQuestPerkEntry;
		inline static constexpr auto VTABLE = VTABLE_BGSQuestPerkEntry;

		~BGSQuestPerkEntry() override;  // 03

		// override (BGSPerkEntry)
		[[nodiscard]] PERK_ENTRY_TYPE GetType() const override;                  // 04 - { return PERK_ENTRY_TYPE::kQuest; }
		void                          InitItem(TESFile* a_owner) override;       // 06
		bool                          Load(TESFile* a_file) override;            // 07
		void                          ApplyPerkEntry(Actor* a_actor) override;   // 0A
		void                          RemovePerkEntry(Actor* a_actor) override;  // 0B - { return; }
		
		// members
		QuestPerkEntryData data = {};  // 10
	};
}
