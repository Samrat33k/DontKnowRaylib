// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "Camera.h"

//...

namespace Brahmanda
{
	void GameCamera2D::Init()
	{
		RayCamera.target = { ViewData.ViewTarget.X, ViewData.ViewTarget.Y };
		RayCamera.rotation = ViewData.Rotation;
		RayCamera.zoom = ViewData.Zoom;
	}

	void GameCamera2D::Reset()
	{

	}

	ECameraType GameCamera::GetCameraType()
	{
		return CameraType;
	}

	void GameCamera3D::Init()
	{
		RayCamera.target = { ViewData.ViewTarget.X, ViewData.ViewTarget.Y, ViewData.ViewTarget.Z };
	}

	void GameCamera3D::Reset()
	{

	}
}