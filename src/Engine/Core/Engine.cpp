// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "Engine.h"

#include "ModuleIncludes.h"
#include "IGame.h"
#include "Engine/Systems/AssetManager.h"
#include "Engine/Systems/Logger.h"

//...

namespace Brahmanda
{
	Engine::Engine()
	{

	}

	bool Engine::InitEngine()
	{
		Logger::InitLogger();

		GlobalAssetManager = std::make_unique<AssetManager>();

		if (GameRef)
		{
			GameRef->SetAssetManager(GlobalAssetManager.get());
			GameRef->Init();
		}

		return true;
	}

	void Engine::CycleEngine(float DeltaTime)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		rlImGuiBegin();

		if (GameRef)
		{
			GameRef->Cycle(DeltaTime);
		}

		rlImGuiEnd();

		EndDrawing();
	}

	void Engine::ShutdownEngine()
	{
		if (GameRef)
		{
			GameRef->Shutdown();
		}
	}

	void Engine::SetGame(IGame* InGame)
	{
		GameRef = InGame;
	}

	AssetManager* Engine::GetGameAssetManager() const
	{
		return GlobalAssetManager.get();
	}

	Engine::~Engine()
	{

	}
}