// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <memory>

#include "AssetTypes.h"

struct Texture;
struct Model;

namespace Brahmanda
{
	class AssetManager
	{
	public:

		AssetManager();
		~AssetManager();

		TextureHandle ReqLoadTexture(const std::string& InPath);
		GeometryHandle ReqLoadGeometry(const std::string& InPath);
		//void AssignTextureToGeo(const GeometryHandl& InHandle, const TextureHandle& InHandle); 

		void UnloadUnused();

		Texture* GetTexture(const TextureHandle& InHandle);
		Model* GetGeometry(const GeometryHandle& InHandle);

	private:

		uint32_t LastTexID = 0U;
		uint32_t LastGeoID = 0U;

		struct TextureEntry
		{
			std::unique_ptr<Texture> Data;
			uint32_t RefCount = 0U;
		};

		std::unordered_map<uint32_t, TextureEntry> LoadedTextureList;
		std::unordered_map<std::string, uint32_t> LoadedTextureIDs;
	};
}