// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "Engine/Core/ModuleIncludes.h"
#include "Engine/Core/CoreIncludes.h"

#include "Engine/Core/IGame.h"
#include "Engine/Framework/AssetTypes.h"

//...

namespace Brahmanda
{
	class AssetManager;
	struct TextureHandle;
	class Mandala;

	class Game : public Brahmanda::IGame
	{
	public:

		Game();
		~Game() override;

		bool Init() override;
		void Cycle(float DeltaTime) override;
		void Shutdown() override;
		void SetAssetManager(Brahmanda::AssetManager* InMgr) override;

	private:

		TextureHandle TestTex;
		TextureHandle TestTex1;
		TextureHandle TestTex2;
		TextureHandle TestTex3;

		AssetManager* Manager = nullptr;
		std::unique_ptr<Mandala> MandalaRef;
	};
}