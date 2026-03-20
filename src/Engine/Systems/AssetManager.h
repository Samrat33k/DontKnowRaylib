// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <memory>

#include "Engine/Core/Types/AssetTypes.h"

struct Texture;
struct Model;

namespace Brahmanda
{
	class AssetManager : public IAssetBridge
	{
	public:

		AssetManager();
		~AssetManager();

		TextureHandle ReqLoadTexture(const std::string& InPath);
		void AddTextureRef(uint32_t InID);
		void ReqUnloadTexture(const TextureHandle& InHandle);
		void ReleaseTexture(uint32_t InID);

		GeometryHandle ReqLoadGeometry(const std::string& InPath);
		void ReqUnloadGeometry(const GeometryHandle& InHandle);
		//void AssignTextureToGeo(const GeometryHandl& InHandle, const TextureHandle& InHandle); 

		void UnloadUnused();

		Texture* GetTexture(const TextureHandle& InHandle);
		Model* GetGeometry(const GeometryHandle& InHandle);

		//Interface Implementation
		void AddAssetRef(uint32_t InID, EAssetType InType) override;
		void ReqUnloadAsset(uint32_t InID, EAssetType InType) override;
		bool GetIsShuttingDown() const override;

	private:

		uint32_t LastTexID = 0U;
		uint32_t LastGeoID = 0U;
		bool bIsShuttingDown = false;

		struct TextureEntry
		{
			std::unique_ptr<Texture> Data;
			uint32_t RefCount = 0U;
			std::string PathToAsset = "";
		};

		std::unordered_map<uint32_t, TextureEntry> LoadedTextureList;
		std::unordered_map<std::string, uint32_t> LoadedTextureIDs;
	};
}