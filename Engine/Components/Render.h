#pragma once
#include "Component.h"

namespace sn {
	class Render : public Component {
	public:
		virtual void Draw() = 0;
	};
}