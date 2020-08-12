#include "pch.h"
#include "InputSystem.h"

bool sn::InputSystem::Startup()
{
	const Uint8* keystate = SDL_GetKeyboardState(&m_numKeys);

	m_keystate = new Uint8[m_numKeys];
	m_prevKeystate = new Uint8[m_numKeys];
	memcpy(m_keystate, keystate, m_numKeys);
	memcpy(m_prevKeystate, keystate, m_numKeys);

	return true;
}

void sn::InputSystem::Shutdown()
{
	delete[] m_keystate;
	delete[] m_prevKeystate;
}

void sn::InputSystem::Update()
{
	memcpy(m_prevKeystate, m_keystate, m_numKeys);
	const Uint8* keystate = SDL_GetKeyboardState(nullptr);
	memcpy(m_keystate, keystate, m_numKeys);
}

sn::InputSystem::eButtonState sn::InputSystem::GetButtonState(int id)
{
	eButtonState state = eButtonState::IDLE;

	bool buttonDown = GetButtonDown(id);
	bool prevButtonDown = GetPreviousButtonDown(id);

	if (buttonDown) {
		state = (prevButtonDown) ? eButtonState::HELD : eButtonState::PRESSED;
	}
	else {
		state = (prevButtonDown) ? eButtonState::RELEASED : eButtonState::IDLE;
	}

	return state;
}

bool sn::InputSystem::GetButtonDown(int id)
{
	return m_keystate[id];
}

bool sn::InputSystem::GetPreviousButtonDown(int id)
{
	return m_prevKeystate[id];
}
