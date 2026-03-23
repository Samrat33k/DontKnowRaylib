// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "MyMandala.h"
#include "Engine/Systems/Logger.h"
#include "Engine/GameFramework/WorldLayer.h"
#include "Engine/Core/Types/RenderableTypes.h"

#include "MyGame/Maps/GameMap01.h"

//...

MyMandala::MyMandala()
{

}

MyMandala::~MyMandala()
{

}

bool MyMandala::Init()
{
	PARENT::Init();

	Logger::Info("MyMandala - Init - Called from Derived class");

	Brahmanda::WorldLayer& Map = WorldLayers.AddLayerAt<GameMap01>(0);
	Map.Load();

	return true;
}

void MyMandala::Cycle(float DeltaTime, Brahmanda::FrameContextData& InContext)
{
	PARENT::Cycle(DeltaTime, InContext);


}

void MyMandala::Shutdown()
{
	Logger::Info("MyMandala - Shutdown - Called from Derived class");

	PARENT::Shutdown();
}
