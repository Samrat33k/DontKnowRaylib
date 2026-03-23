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


	}

	void Brahmanda::Renderer::ShutdownRenderer()
	{

	}

	void Brahmanda::Renderer::BeginRenderFrame()
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		rlImGuiBegin();
	}

	void Renderer::RenderFrame(const RenderQueue& InRenderQueue)
	{
		for (RenderData Item : InRenderQueue.GetRenderItems())
		{
			
		}
	}

	void Brahmanda::Renderer::EndRenderFrame()
	{
		rlImGuiEnd();

		EndDrawing();
	}
}