// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "Engine/Core/Types/CustomTypes.h"

//...

namespace Brahmanda
{
	class Camera
	{
	public:

		Camera();
		~Camera();

		virtual void Reset() = 0;
	};

	class Camera2D : public Camera
	{

	};

	class Camera3D : public Camera
	{

	};
}
