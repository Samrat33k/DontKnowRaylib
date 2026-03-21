// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include <cstdint>
#include <array>

#include "GameConfig.h"
#include "WorldLayer.h"
#include "WorldLayerCollection.h"

//...

namespace Brahmanda
{
	class WorldLayer;

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

		virtual bool Init();
		virtual void Cycle(float DeltaTime);
		virtual void Shutdown();

		//void AddLayerToCollection();
		//virtual void AddLayerToCollectionCustom();

		void SetWorldConfig(const WorldConfig& InConfig);

	private:

		uint16_t ActiveWorldLayerCount = 0;
		WorldLayerCollection<Config::World::MAX_WORLD_LAYER_COUNT> Collection;
	};
}