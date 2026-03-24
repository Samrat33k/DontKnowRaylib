// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "Renderer.h"
#include "ModuleIncludes.h"
#include "Engine/Systems/Logger.h"
#include "raylib.h"
#include "Engine/Systems/AssetManager.h"

//...

namespace Brahmanda
{
	Renderer::Renderer()
	{

	}

	Renderer::~Renderer()
	{

	}

	void Brahmanda::Renderer::InitRenderer(AssetManager* InRef)
	{
		AssetManagerRef = InRef;

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
 			Texture* Tex = AssetManagerRef->GetTexture(Item.Tex);

			if (Tex)
			{
				DrawTexturePro(*Tex, { 0, 0, (float)Tex->width, (float)Tex->height }, { 150, 150, 100, 100 }, {}, 0, WHITE);
			}
		}
	}

	void Brahmanda::Renderer::EndRenderFrame()
	{
		rlImGuiEnd();

		EndDrawing();
	}
}