// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "Engine/Core/ModuleIncludes.h"
#include "Engine/Core/CoreIncludes.h"

#include "Engine/Core/IGame.h"

class Game : public Brahmanda::IGame
{
public:

	Game();
	~Game() override;

	bool InitGame() override;
	void CycleGame() override;
	void ShutdownGame() override;

private:

	Texture TestTexture = {};
};