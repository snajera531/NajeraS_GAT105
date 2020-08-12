#include "pch.h"
#include "Vector2.h"

namespace sn {
	const Vector2 Vector2::left{ -1, 0 };
	const Vector2 Vector2::right{ 1,0 };
	const Vector2 Vector2::up{ 0, -1 };
	const Vector2 Vector2::down{ 0, 1 };
	const Vector2 Vector2::forward{ 0, -1 };

	std::istream& operator >> (std::istream& stream, Vector2& v)
	{
		std::string line;
		std::getline(stream, line);

		if (line.find("{") != std::string::npos)
		{
			// { 0, -3 }
			std::string vx = line.substr(line.find("{") + 1, line.find(",") - line.find("{") - 1);
			v.x = std::stof(vx);
			std::string vy = line.substr(line.find(",") + 1, line.find("}") - line.find(",") - 1);
			v.y = std::stof(vy);
		}

		return stream;
	}
}