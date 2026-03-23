// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "Mandala.h"
#include "Engine/Systems/Logger.h"
#include "Engine/Core/Types/RenderableTypes.h"

//...

namespace Brahmanda
{
	Mandala::Mandala()
	{

	}

	Mandala::~Mandala()
	{

	}

	bool Mandala::Init()
	{
		Logger::Info("Mandala - Init - Called from Base class!");

		return true;
	}

	void Mandala::Cycle(float DeltaTime, FrameContextData& InContext)
	{
		for (auto& It : Collection.GetLayerList())
		{
			if (It && It->GetIsLoaded())
			{
				
			}
		}
	}

	void Mandala::Shutdown()
	{
		Logger::Info("Mandala - Shutdown - Called from Base class!");
	}

	void Mandala::SetWorldConfig(const WorldConfig& InConfig)
	{
		
	}
}