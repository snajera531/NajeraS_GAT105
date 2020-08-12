#pragma once
#include "Core/Timer.h"
#include "Graphics/Renderer.h"
#include "Input/InputSystem.h"
#include "Resources/ResourceManager.h"
#include <vector>

namespace sn {
	class System;

	class Engine {
	public:
		bool Startup();
		void Shutdown();

		void Update();

	protected:
		std::vector<System*> m_systems;
	};
}