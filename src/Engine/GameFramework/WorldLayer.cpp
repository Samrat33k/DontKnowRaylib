// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "WorldLayer.h"

//...

namespace Brahmanda
{
	WorldLayer::WorldLayer()
	{

	}

	WorldLayer::~WorldLayer()
	{

	}

	void WorldLayer::Load()
	{
		bIsLoaded = true;
	}

	void WorldLayer::Unload()
	{
		bIsLoaded = false;
	}

	bool WorldLayer::GetIsLoaded() const
	{
		return bIsLoaded;
	}
	bool WorldLayer::GetIsVisible() const
	{
		return bIsVisible;
	}
}