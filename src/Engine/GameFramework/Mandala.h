// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include <cstdint>
#include <array>

#include "GameConfig.h"
#include "WorldLayer.h"
#include "WorldLayerCollection.h"
#include "LayerInitData.h"

//...

namespace Brahmanda
{
	class FrameContextData;
	class WorldLayer;
	class AssetManager;

	struct WorldConfig
	{
	public:

		WorldConfig()
		{

		}

		~WorldConfig()
		{

		}

	private:

	};

	class Mandala
	{
	public:

		using PARENT = Brahmanda::Mandala;

		Mandala();
		virtual ~Mandala();

		bool Init();
		virtual void OnInit();
		virtual void PostInit();
		void Cycle(float DeltaTime, FrameContextData& InContext);
		virtual void OnCycle(float DeltaTime);
		void Shutdown();
		virtual void OnShutdown();

		void SetWorldConfig(const WorldConfig& InConfig);
		void SetAssetManager(AssetManager* InRef);

	protected:

		WorldLayerCollection<Config::World::MAX_WORLD_LAYER_COUNT> Collection;
		LayerInitData LayerData;

	private:

		AssetManager* Manager = nullptr;
		uint16_t ActiveWorldLayerCount = 0;
	};
}