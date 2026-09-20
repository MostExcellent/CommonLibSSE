#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	class IMovementDirectControl : public IMovementInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementDirectControl;
		inline static constexpr auto VTABLE = VTABLE_IMovementDirectControl;

		~IMovementDirectControl() override;  // 00

		// add
		virtual void SetDirectControl() = 0;                                                       // 01
		virtual void SetMovementDirection(const NiPoint3& a_directionEuler) = 0;                   // 02
		virtual void SetMovementSpeed(float a_speedMult) = 0;                                      // 03
		virtual void SetMovementRotationSpeed(const NiPoint3& a_rotationSpeedMult) = 0;            // 04
		virtual void RampToMovementDirection(const NiPoint3& a_directionEuler, float a_time) = 0;  // 05
		virtual void RampToMovementSpeed(float a_speedMult, float a_time) = 0;                     // 06
		virtual void RampToRotationSpeed(const NiPoint3& a_rotationSpeedMult, float a_time) = 0;   // 07
		virtual void ClearDirectControl() = 0;  // 08
	};
	static_assert(sizeof(IMovementDirectControl) == 0x8);
}
