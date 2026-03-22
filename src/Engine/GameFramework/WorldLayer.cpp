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

	bool WorldLayer::GetIsLoaded() const
	{
		return bIsLoaded;
	}
	bool WorldLayer::GetIsVisible() const
	{
		return bIsVisible;
	}
}