// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include <cstdint>

//...

namespace Brahmanda
{
	struct WorldConfig
	{
	public:

		WorldConfig()
		{

		}

		~WorldConfig()
		{

		}

		void SetMaxWorldLayerCount(uint16_t InNewCount)
		{
			if (InNewCount == 0U)
			{
				MaxWorldLayers = 1;
				
				return;
			}

			MaxWorldLayers = InNewCount;
		}

	private:

		uint16_t MaxWorldLayers = 8;
	};

	class Mandala
	{
	public:

		Mandala();
		~Mandala();

		bool Init();
		void Cycle(float DeltaTime);
		void Shutdown();

		void SetWorldConfig();
	};
}