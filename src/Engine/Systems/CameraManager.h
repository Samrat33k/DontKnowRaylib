// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "Engine/GameFramework/Elements/Camera.h"

//...

namespace Brahmanda
{
	class CameraManager
	{
	public:

		CameraManager();
		~CameraManager();

	private:

		Brahmanda::Camera* ActiveCamera = nullptr;
	};
}