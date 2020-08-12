#include "pch.h"
#include "Transform.h"
#include "Matrix33.h"

namespace sn {
	std::istream& sn::operator>>(std::istream& stream, Transform& transform)
	{
		stream >> transform.position;

		std::string line;

		std::getline(stream, line);
		transform.scale = stof(line);

		std::getline(stream, line);
		transform.angle = stof(line);

		return stream;
	}
	void Transform::Update()
	{
		sn::Matrix33 mxs;
		mxs.Scale(scale);

		sn::Matrix33 mxr;
		mxr.Rotate(angle);

		sn::Matrix33 mxt;
		mxt.Translate(position);

		matrix = mxs * mxr * mxt;

	}
}

