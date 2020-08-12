#pragma once
#include "Matrix33.h"

namespace sn {
	struct Transform {
		Vector2 position;
		float scale{ 1 };
		float angle{ 0 };
		Matrix33 matrix;

		Transform() : position{0,0}, scale{1}, angle{0} {}
		Transform(const Vector2& position, float scale = 1, float angle = 0) : position{position}, scale{scale}, angle{angle}{}

		friend std::istream& operator >> (std::istream& strea, Transform& transform);
		void Update();
	};
}