// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "Engine/Core/ModuleIncludes.h"
#include "Engine/Core/CoreIncludes.h"

#include "Engine/Core/IGame.h"
#include "Engine/Core/Types/HandleTypes.h"

//...


namespace Brahmanda
{
	class AssetManager;
	struct TextureHandle;
	class Mandala;
	struct FrameContextData;

	class Game : public Brahmanda::IGame
	{
	public:

		using PARENT = Brahmanda::Game;

		Game();
		~Game() override;

		bool Init() override;
		virtual void OnInit();
		void Cycle(float DeltaTime, FrameContextData& InContext) override;
		virtual void OnCycle(float DeltaTime);
		void Shutdown() override;
		virtual void OnShutdown();

		AssetManager* GetAssetManager() const;
		void SetAssetManager(Brahmanda::AssetManager* InRef) override;

		virtual std::unique_ptr<Mandala> ConstructMandala();
		Mandala* GetGameMandala() const;

	private:

		AssetManager* Manager = nullptr;
		std::unique_ptr<Mandala> MandalaRef;
	};
}