#include "pch.h"
#include "Physics.h"
#include "Objects/GameObject.h"

namespace sn {
	bool sn::Physics::Create(void* data)
	{
		return false;
	}

	void sn::Physics::Destroy()
	{

	}

	void sn::Physics::Update()
	{
		m_velocity += m_force;// timer.DeltaTime();
		m_velocity *= m_drag;
		m_owner->m_transform.position += m_velocity; // timer.DeltaTime();
	}
}
