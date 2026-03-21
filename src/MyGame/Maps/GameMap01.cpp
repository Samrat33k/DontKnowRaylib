// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "GameMap01.h"
#include "MyGame/Data/Block.h"
#include "Engine/Systems/Logger.h"

//...

GameMap01::GameMap01()
{
	Logger::Info("Constructed GameMap01!");
}

GameMap01::~GameMap01()
{

}

void GameMap01::Create(int InW, int InH)
{
	*this = {};
	MapData.resize(InW * InH);

	w = InW;
	h = InH;

	for (auto It : MapData)
	{
		It = {};
	}
}

Block& GameMap01::GetBlockUnsafe(int InX, int InY)
{
	//Logger::Fatal("Unsafe");

	return MapData[InX + InY * w];
}

Block* GameMap01::GetBlockSafe(int InX, int InY)
{
	return &MapData[InX + InY * w];
}
