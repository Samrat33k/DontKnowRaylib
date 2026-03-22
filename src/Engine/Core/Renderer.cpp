#include "Renderer.h"
#include "Renderer.h"
#include "Renderer.h"
#include "Renderer.h"
#include "Renderer.h"
// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "Renderer.h"
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

	void Brahmanda::Renderer::CycleRenderer()
	{

	}

	void Brahmanda::Renderer::ShutdownRenderer()
	{

	}

	void Brahmanda::Renderer::BeginRenderFrame()
	{

	}

	void Brahmanda::Renderer::EndRenderFrame()
	{

	}
}