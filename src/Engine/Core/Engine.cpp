// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "Engine.h"

#include "IGame.h"
#include "Engine/Systems/AssetManager.h"
#include "Engine/Core/Renderer.h"
#include "Engine/Core/Types/RenderableTypes.h"
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
		GlobalAssetManager->Init();
		RendererRef = std::make_unique<Renderer>();
		RendererRef->InitRenderer(GlobalAssetManager.get());

		RenderQueueRef = std::make_unique<RenderQueue>();
		RenderQueueRef->ReserveSize(1000);
		RenderQueueRef->Clear();

		if (GameRef)
		{
			GameRef->SetAssetManager(GlobalAssetManager.get());
			GameRef->Init();

			return true;
		}

		return false;
	}

	void Engine::CycleEngine(float DeltaTime)
	{
		RenderQueue& Queue = *RenderQueueRef;
		Queue.Clear();

		RendererRef->BeginRenderFrame();

		FrameContextData FrameContext(Queue);
		GameRef->Cycle(DeltaTime, FrameContext);

		RendererRef->RenderFrame(Queue);

		RendererRef->EndRenderFrame();
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