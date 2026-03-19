// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "CoreIncludes.h"

namespace Brahmanda
{
	class AssetManager;

	class IGame
	{
	public:

		virtual ~IGame() = default;

		virtual bool Init() = 0;
		virtual void Cycle(float DeltaTime) = 0;
		virtual void Shutdown() = 0;

		virtual void SetAssetManager(AssetManager* InMgr) = 0;
	};
}