// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include <vector>

//...

namespace Brahmanda
{
	class Entity;

	class WorldLayer
	{
	public:

		WorldLayer();
		~WorldLayer();

		void Load();
		void Unload();
		
		bool GetIsLoaded() const;
		bool GetIsVisible() const;

		//std::vector<Entity> Entities;

	private:

		bool bIsLoaded = false;
		bool bIsVisible = false;
	};
}