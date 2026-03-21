// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "Game.h"
#include "Engine/Systems/AssetManager.h"
#include "Engine/Systems/Logger.h"
#include "Mandala.h"

//...

namespace Brahmanda
{
	Game::Game()
	{

	}

	bool Game::Init()
	{
		Logger::Info("Game Initialized!");

		MandalaRef = ConstructMandala();
		MandalaRef->Init();

		return true;
	}

	void Game::Cycle(float DeltaTime)
	{
		MandalaRef->Cycle(DeltaTime);

	}

	void Game::Shutdown()
	{
		MandalaRef->Shutdown();

		//...
	}

	AssetManager* Game::GetAssetManager() const
	{
		return Manager;
	}

	void Game::SetAssetManager(Brahmanda::AssetManager* InMgr)
	{
		Manager = InMgr;
	}

	std::unique_ptr<Mandala> Game::ConstructMandala()
	{
		return std::make_unique<Mandala>();
	}

	Mandala* Game::GetGameMandala() const
	{
		return MandalaRef.get();
	}

	Game::~Game()
	{

	}
}