#pragma once

#include "RE/I/IAnimationSetCallbackFunctor.h"
#include "RE/I/IMovementDirectControl.h"
#include "RE/I/IMovementMessageInterface.h"
#include "RE/I/IMovementMotionDrivenControl.h"
#include "RE/I/IMovementPlannerDirectControl.h"
#include "RE/I/IMovementSelectIdle.h"
#include "RE/M/MovementControllerAI.h"

namespace RE
{
	class MovementControllerNPC :
		public MovementControllerAI,           // 000
		public IMovementMessageInterface,      // 120
		public IMovementMotionDrivenControl,   // 128
		public IMovementSelectIdle,            // 130
		public IMovementDirectControl,         // 138
		public IMovementPlannerDirectControl,  // 140
		public IAnimationSetCallbackFunctor    // 148
	{
	public:
		inline static constexpr auto RTTI = RTTI_MovementControllerNPC;
		inline static constexpr auto VTABLE = VTABLE_MovementControllerNPC;

		~MovementControllerNPC() override;  // 00

		// override (IMovementDirectControl)
		void SetDirectControl() override;
		void SetMovementDirection(const NiPoint3& a_directionEuler) override;
		void SetMovementSpeed(float a_speedMult) override;
		void SetMovementRotationSpeed(const NiPoint3& a_rotationSpeedMult) override;
		void RampToMovementDirection(const NiPoint3& a_directionEuler, float a_time) override;
		void RampToMovementSpeed(float a_speedMult, float a_time) override;
		void RampToRotationSpeed(const NiPoint3& a_rotationSpeedMult, float a_time) override;
		void ClearDirectControl() override;

		// override (IMovementPlannerDirectControl)
		void SetPlannerDirectControl() override;
		void SetPlannerTargetDirection(const NiPoint3& a_directionEuler) override;
		void SetPlannerTargetSpeed(float a_speedMult) override;
		void SetPlannerTargetAngle(const NiPoint3& a_angle) override;
		void ClearPlannerDirectControl() override;

		// add
		virtual void Unk_0A(void);         // 0A
		virtual void Unk_0B(void);         // 0B
		virtual void SetAIDriven();        // 0C
		virtual void SetControlsDriven();  // 0D
		virtual bool GetAIDriven();        // 0E - { return controlsDriven == 0; }
		virtual bool GetControlsDriven();  // 0F - { return controlsDriven; }
		virtual void Unk_10(void);         // 10
		virtual void Unk_11(void);         // 11
		virtual void Unk_12(void);         // 12
		virtual void Unk_13(void);         // 13
		virtual void Unk_14(void);         // 14

		// members
		std::uint64_t unk150;          // 150
		std::uint64_t unk158;          // 158
		std::uint64_t unk160;          // 160
		std::uint64_t unk168;          // 168
		std::uint64_t unk170;          // 170
		std::uint64_t unk178;          // 178
		std::uint64_t unk180;          // 180
		std::uint64_t unk188;          // 188
		std::uint64_t unk190;          // 190
		std::uint64_t unk198;          // 198
		std::uint64_t unk1A0;          // 1A0
		std::uint64_t unk1A8;          // 1A8
		std::uint64_t unk1B0;          // 1B0
		std::uint64_t unk1B8;          // 1B8
		std::uint32_t unk1C0;          // 1C0
		std::uint8_t  unk1C4;          // 1C4
		bool          controlsDriven;  // 1C5
		bool          directControl;   // 1C6 - Set by SetDirectControl - unsure "real" name
		bool		  unk1C7;          // 1C7
		std::uint64_t unk1C8;          // 1C8
	};
	static_assert(sizeof(MovementControllerNPC) == 0x1D0);
}
