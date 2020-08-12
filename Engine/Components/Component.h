#pragma once
#include "Objects/Object.h"

namespace sn {
	class GameObject;

	class Component : public Object {
	public:
		virtual void Update() = 0;

		friend class GameObject;

	protected:
		GameObject* m_owner{ nullptr };
	};
}