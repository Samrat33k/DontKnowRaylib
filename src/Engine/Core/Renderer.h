// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include <memory>
#include "Types/RenderableTypes.h"

//...

namespace Brahmanda
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void InitRenderer();

		void BeginRenderFrame();
		void RenderFrame(const RenderQueue& InRenderQueue);
		void EndRenderFrame();
		
		void ShutdownRenderer();

	private:

	};
}