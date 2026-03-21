// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "Engine/GameFramework/Game.h"

//...

namespace Brahmanda
{
	struct TextureHandle;
	class AssetManager;
}

class Brahmanda::Mandala;

class MyGame : public Brahmanda::Game
{
public:

	MyGame();
	~MyGame();

	bool Init() override;
	void Cycle(float DeltaTime) override;
	void Shutdown() override;

	std::unique_ptr<Brahmanda::Mandala> ConstructMandala() override;

private:

	Brahmanda::TextureHandle TestTex;
	Brahmanda::TextureHandle TestTex1;
	Brahmanda::TextureHandle TestTex2;
	Brahmanda::TextureHandle TestTex3;

	Brahmanda::AssetManager* ManagerRef = nullptr;
};