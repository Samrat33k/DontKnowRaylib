// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "MyMandala.h"
#include "Engine/Systems/Logger.h"
#include "MyGame/Maps/GameMap01.h"
#include "MyGame/Data/Block.h"

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

	WorldLayers.AddLayerAt<GameMap01>(0);
	GameMap01* Map = static_cast<GameMap01*>(WorldLayers.GetLayerAt(0));
	
	Map->Create(30, 10);

	Map->GetBlockUnsafe(0, 0).Type = Block::dirt;
	Map->GetBlockUnsafe(1, 1).Type = Block::dirt;
	Map->GetBlockUnsafe(2, 2).Type = Block::dirt;
	Map->GetBlockUnsafe(3, 3).Type = Block::dirt;
	Map->GetBlockUnsafe(4, 4).Type = Block::dirt;

	return true;
}

void MyMandala::Cycle(float DeltaTime)
{
	PARENT::Cycle(DeltaTime);


}

void MyMandala::Shutdown()
{
	Logger::Info("MyMandala - Shutdown - Called from Derived class");

	PARENT::Shutdown();
}
