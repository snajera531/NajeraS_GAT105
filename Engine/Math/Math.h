#pragma once
#include "Vector2.h"

namespace sn {
	const float PI = 3.1415f;
	const float TWO_PI = PI * 2;

	inline float RadiansToDegrees(float radians) {
		return radians * (180.0f / PI);
	}

	inline float DegreesToRadians(float degrees) {
		return degrees * (PI / 180.0f);
	}

	template <typename T>
	inline T clamp(T v, T min, T max) {
		if (v < min) {
			v = min;
		}
		if (v > max) {
			v = max;
		}
		return v;
	}

	template <>
	inline sn::Vector2 clamp<sn::Vector2>(sn::Vector2 v, sn::Vector2 min, sn::Vector2 max) {
		v.x = clamp(v.x, min.x, max.x);
		v.y = clamp(v.y, min.y, max.y);	

		return v;
	}

	template <typename T>
	inline T lerp(T a, T b, float t) {
		t = clamp(t, 0.0f, 1.0f);
		return (a + ((b - a) * t));
	}
}


