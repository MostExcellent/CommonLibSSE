#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class BGSActionData;
	struct BSAnimationGraphEvent;
	class Actor;
	class TESObjectREFR;

	class ActorMediator :
		public BSTEventSink<BSAnimationGraphEvent>,
		public BSTSingletonSDM<ActorMediator>
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActorMediator;
		inline static constexpr auto VTABLE = VTABLE_ActorMediator;

		using EventCallback = BSEventNotifyControl(const BSAnimationGraphEvent*, BSTEventSource<BSAnimationGraphEvent>*);

		~ActorMediator() override = default;  // 00

		// override (BSTEventSink<BSAnimationGraphEvent>)
		BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;  // 01

#ifdef SKYRIM_SUPPORT_AE // TODO: work out IDs for 1.5.97
		static ActorMediator* Get();

		bool DoAction(BGSActionData& a_action);
#endif

		std::uint64_t pad08;

		// members
		EventCallback* callback;  // 10
	};
	static_assert(sizeof(ActorMediator) == 0x18);
	static_assert(offsetof(ActorMediator, callback) == 0x10);
}
