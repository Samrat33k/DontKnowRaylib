// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

//...

namespace Brahmanda
{
	struct RenderTransform
	{
		//Custom wrapper to support other data formats in future.
		//For now things will be simpler

		//Positions
		float Pos[3] = { 0.f, 0.f, 0.f };

		//Rotations
		float Rot[3] = { 0.f, 0.f, 0.f };

		//Scales
		float Scale[3] = { 1.f, 1.f, 1.f };

		//To be extended further as per requirement
	};
}