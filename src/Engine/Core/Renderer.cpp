// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "Renderer.h"
#include "ModuleIncludes.h"
#include "Engine/Systems/Logger.h"

//...

namespace Brahmanda
{
	Renderer::Renderer()
	{

	}

	Renderer::~Renderer()
	{

	}

	void Brahmanda::Renderer::InitRenderer()
	{
		RenderQueueRef = std::make_unique<RenderQueue>();
		RenderQueueRef->ReserveSize();
		RenderQueueRef->Clear();

	}

	void Brahmanda::Renderer::ShutdownRenderer()
	{

	}

	RenderQueue* Renderer::GetRenderQueue()
	{
		return RenderQueueRef.get();
	}

	void Brahmanda::Renderer::BeginRenderFrame()
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		rlImGuiBegin();
	}

	void Renderer::RenderFrame()
	{
		for (RenderData Item : RenderQueueRef->GetRenderItems())
		{
			
		}
	}

	void Brahmanda::Renderer::EndRenderFrame()
	{
		rlImGuiEnd();

		EndDrawing();
	}
}