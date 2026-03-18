// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "Engine.h"

#include "ModuleIncludes.h"
#include "IGame.h"

//...

namespace Brahmanda
{
	Engine::Engine()
	{
		
	}

	bool Engine::InitEngine()
	{
		if (GameRef)
		{
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

	Engine::~Engine()
	{

	}
}