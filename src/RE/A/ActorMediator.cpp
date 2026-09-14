#include "RE/A/ActorMediator.h"

RE::ActorMediator* RE::ActorMediator::Get()
{
	const REL::Relocation<ActorMediator**> singleton{ REL::ID(403567) };  // TODO:SE
	return *singleton;
}

bool RE::ActorMediator::DoAction(BGSActionData& a_action)
{
	using func_t = decltype(&ActorMediator::DoAction);
	static REL::Relocation<func_t> func{ REL::ID(38949) };  // TODO:SE
	return func(this, a_action);
}
