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
	class FrameContextData;
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
		virtual void Cycle(float DeltaTime, FrameContextData& InContext);
		virtual void Shutdown();

		void SetWorldConfig(const WorldConfig& InConfig);

	protected:

		WorldLayerCollection<Config::World::MAX_WORLD_LAYER_COUNT> Collection;

	private:

		uint16_t ActiveWorldLayerCount = 0;
	};
}