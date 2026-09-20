#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	class IMovementPlannerDirectControl : public IMovementInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementPlannerDirectControl;
		inline static constexpr auto VTABLE = VTABLE_IMovementPlannerDirectControl;

		~IMovementPlannerDirectControl() override;  // 00

		// add
		virtual void SetPlannerDirectControl() = 0;                                    // 01
		virtual void SetPlannerTargetDirection(const NiPoint3& a_directionEuler) = 0;  // 02
		virtual void SetPlannerTargetSpeed(float a_speedMult) = 0;                     // 03
		virtual void SetPlannerTargetAngle(const NiPoint3& a_angle) = 0;               // 04
		virtual void ClearPlannerDirectControl() = 0;                                  // 05
	};
	static_assert(sizeof(IMovementPlannerDirectControl) == 0x8);
}
