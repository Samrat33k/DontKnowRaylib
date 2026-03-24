// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "WorldLayer.h"

#include "Engine/Core/Types/RenderableTypes.h"
#include "Engine/Core/Types/HandleTypes.h"
#include "Engine/Core/Types/CustomTypes.h"
#include "Engine/GameFramework/ECS/Entity.h"

//...

namespace Brahmanda
{
	WorldLayer::WorldLayer(const LayerInitData& InData)
	{
		AssetManagerRef = InData.AssetMgr;
	}

	WorldLayer::~WorldLayer()
	{

	}

	void WorldLayer::Load()
	{
		for (auto& It : Entities)
		{
			if (It)
			{
				//Need path based texture loading
				//It->Tex = AssetManagerRef->ReqLoadTexture(RESOURCE_DIR "Dirt")
			}
		}

		bIsLoaded = true;

		OnLoad();
	}

	void WorldLayer::Unload()
	{
		OnUnload();

		bIsLoaded = false;
	}

	void WorldLayer::OnLoad()
	{

	}

	void WorldLayer::OnUnload()
	{

	}

	void WorldLayer::SubmitForRender(RenderQueue& InQueue)
	{
		for (auto& It : Entities)
		{
			if (It)
			{
				TextureHandle& t = It->Tex;
				if (!t.GetIsVisible())
				{
					continue;
				}

				RenderData Data;
				Data.Tex = t;
				Data.Transform = It->Transform;
				InQueue.Submit(std::move(Data));
			}
		}
	}

	bool WorldLayer::GetIsLoaded() const
	{
		return bIsLoaded;
	}

	bool WorldLayer::GetIsVisible() const
	{
		return bIsVisible;
	}

	void WorldLayer::SetAssetManager(AssetManager* InRef)
	{
		AssetManagerRef = InRef;
	}
}