// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "Engine/Core/Types/CustomTypes.h"

//...

namespace Brahmanda
{
	enum class ECameraType
	{
		ECT_NONE,
		ECT_2DCamera,
		ECT_3DCamera
	};

	class Camera
	{
	public:

		Camera(ECameraType InType)
			: CameraType(InType)
		{

		}

		Camera() = delete;

		~Camera() = default;

		void Init()
		{

		}

		virtual void Reset() = 0;

	private:

		ECameraType CameraType = ECameraType::ECT_NONE;
	};

	class Camera2D : public Camera
	{
		Camera2D()
			: Camera(ECameraType::ECT_2DCamera)
		{

		}

		void Reset() override
		{

		}
	};

	class Camera3D : public Camera
	{
		Camera3D()
			: Camera(ECameraType::ECT_3DCamera)
		{

		}

		void Reset() override
		{

		}
	};
}
