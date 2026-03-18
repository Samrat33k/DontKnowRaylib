// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

namespace Brahmanda
{
	struct AssetHandle
	{
		AssetHandle()
		{

		}

		AssetHandle(uint32_t InID) :
			AssetID(InID)
		{

		}

		uint32_t GetID() const
		{
			return AssetID;
		}

		uint32_t AssetID = 0U;
	};

	struct TextureHandle : public AssetHandle
	{
		//Additional Data

		TextureHandle()
		{
			AssetID = 0U;
		}

		TextureHandle(uint32_t InID) :
			AssetHandle(InID)
		{

		}
	};

	struct GeometryHandle : public AssetHandle
	{
		//Additional Data

		GeometryHandle()
		{
			AssetID = 0U;
		}

		GeometryHandle(uint32_t InID) :
			AssetHandle(InID)
		{

		}
	};
}