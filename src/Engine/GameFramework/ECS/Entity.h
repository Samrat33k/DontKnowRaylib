// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "Engine/Core/Types/CustomTypes.h"
#include "Engine/Core/Types/HandleTypes.h"

//...

namespace Brahmanda
{
	class Entity
	{
	public:

		Entity(const RenderTransform& InTransform)
			: Transform(InTransform)
		{

		}

		Entity() = delete;
		~Entity() = default;

		TextureHandle Tex = {};
		GeometryHandle Geo = {};

		RenderTransform Transform = {};
	};
}