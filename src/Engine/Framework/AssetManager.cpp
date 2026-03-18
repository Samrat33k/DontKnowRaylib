// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "AssetManager.h"

#include <raylib.h>
#include <spdlog/spdlog.h>

//...

namespace Brahmanda
{
	AssetManager::AssetManager()
	{

	}

	AssetManager::~AssetManager()
	{

	}

	TextureHandle AssetManager::ReqLoadTexture(const std::string& InPath)
	{
		auto It = LoadedTextureIDs.find(InPath);
		if (It != LoadedTextureIDs.end())
		{
			LoadedTextureList[It->second].RefCount += 1;
			spdlog::info("Loaded Texture found. TexId: {}, Ref count: {}", It->second, LoadedTextureList[It->second].RefCount);
			return TextureHandle(It->second);
		}

		uint32_t TexID = ++LastTexID;
		LoadedTextureIDs[InPath] = TexID;

		TextureEntry NewEntry;
		NewEntry.Data = std::make_unique<Texture>(LoadTexture(InPath.c_str()));
		NewEntry.RefCount += 1;
		LoadedTextureList[TexID] = std::move(NewEntry);
		spdlog::info("New texture loaded.TexID: {}, Ref count: {}", TexID, LoadedTextureList[TexID].RefCount);

		return TextureHandle(TexID);
	}

	GeometryHandle AssetManager::ReqLoadGeometry(const std::string& InPath)
	{

		return GeometryHandle();
	}

	void AssetManager::UnloadUnused()
	{

	}

	Texture* AssetManager::GetTexture(const TextureHandle& InHandle)
	{
		auto It = LoadedTextureList.find(InHandle.GetID());
		if (It != LoadedTextureList.end())
		{
			return It->second.Data.get();
		}

		return nullptr;
	}

	Model* AssetManager::GetGeometry(const GeometryHandle& InHandle)
	{

		return nullptr;
	}
}