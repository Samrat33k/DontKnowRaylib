// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include <vector>
#include "HandleTypes.h"

//...

namespace Brahmanda
{
	struct RenderTransform
	{
		//Custom wrapper to support other data formats in future.
		//For now things will be simpler

		//Positions
		float Pos[3] = {0.f, 0.f, 0.f};

		//Rotations
		float Rot[3] = {0.f, 0.f, 0.f};

		//Scales
		float Scale[3] = {1.f, 1.f, 1.f};

		//To be extended further as per requirement
	};

	struct RenderData
	{
		GeometryHandle Geo;
		TextureHandle Tex;

		RenderTransform Transform;

		//To be extended further as per requirement
	};

	class RenderQueue
	{
	public:

		RenderQueue() {};
		~RenderQueue() {};

		void ReserveSize(size_t InCount = 1000)
		{
			RenderItems.reserve(InCount);
		}

		void Clear()
		{
			RenderItems.clear();
		}

		void Submit(RenderData&& InData)
		{
			RenderItems.emplace_back(std::move(InData));
		}

		const std::vector<RenderData>& GetRenderItems() const
		{
			return RenderItems;
		}
		
	private:

		std::vector<RenderData> RenderItems;
	};

	struct FrameContextData
	{
		FrameContextData(RenderQueue& InQueue) :
			PrimaryQueue(InQueue)
		{

		}

		FrameContextData(const FrameContextData&) = default;
		FrameContextData operator=(const FrameContextData&) = delete;

		RenderQueue& PrimaryQueue;

		//To be expanded further as per requirement
	};
}