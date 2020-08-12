#pragma once

namespace sn {
	class Object {
	public:
		virtual bool Create(void* data = nullptr) = 0;
		virtual void Destroy() = 0;
	};
}