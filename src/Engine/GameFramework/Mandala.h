// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include <cstdint>
#include <array>

#include "GameConfig.h"
#include "WorldLayer.h"

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

		Mandala();
		~Mandala();

		bool Init();
		void Cycle(float DeltaTime);
		void Shutdown();

		void SetWorldConfig(const WorldConfig& InConfig);

	private:

		uint16_t ActiveWorldLayerCount = 0;
		std::array<WorldLayer, Config::World::MAX_WORLD_LAYER_COUNT> Worlds;
	};
}