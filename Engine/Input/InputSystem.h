#pragma once
#include "Core/System.h"

namespace sn {
	class InputSystem : public System {
	public:
		enum eButtonState {
			IDLE,
			PRESSED,
			HELD,
			RELEASED
		};

	public:
		virtual bool Startup() override;
		virtual void Shutdown() override;
		virtual void Update() override;

		eButtonState GetButtonState(int id);
		bool GetButtonDown(int id);
		bool GetPreviousButtonDown(int id);

	protected:
		Uint8* m_keystate;
		Uint8* m_prevKeystate;
		int m_numKeys;
	};
}