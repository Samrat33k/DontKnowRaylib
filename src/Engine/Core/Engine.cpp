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
			GameRef->InitGame();
		}
		
		return true;
	}

	void Engine::CycleEngine()
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		rlImGuiBegin();

		if (GameRef)
		{
			GameRef->CycleGame();
		}

		rlImGuiEnd();

		EndDrawing();
	}

	void Engine::ShutdownEngine()
	{

	}

	void Engine::SetGame(IGame* InGame)
	{
		GameRef = InGame;
	}

	Engine::~Engine()
	{

	}
}