// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "Engine/Core/ModuleIncludes.h"
#include "Engine/Core/CoreIncludes.h"

#include "Engine/Core/IGame.h"
#include "Engine/Core/Types/AssetTypes.h"

//...


namespace Brahmanda
{
	class AssetManager;
	struct TextureHandle;
	class Mandala;

	class Game : public Brahmanda::IGame
	{
	public:

		using PARENT = Brahmanda::Game;

		Game();
		~Game() override;

		bool Init() override;
		void Cycle(float DeltaTime) override;
		void Shutdown() override;
		
		AssetManager* GetAssetManager() const;
		void SetAssetManager(Brahmanda::AssetManager* InMgr) override;
		Mandala* GetGameMandala() const;

	private:

		AssetManager* Manager = nullptr;
		std::unique_ptr<Mandala> MandalaRef;
	};
}