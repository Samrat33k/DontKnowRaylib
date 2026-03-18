// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "Engine/Core/ModuleIncludes.h"
#include "Engine/Core/CoreIncludes.h"

#include "Engine/Core/IGame.h"
#include "Engine/Framework/AssetTypes.h"

namespace Brahmanda
{
	class AssetManager;
	struct TextureHandle;
}

class Game : public Brahmanda::IGame
{
public:

	Game();
	~Game() override;

	bool Init() override;
	void Cycle(float DeltaTime) override;
	void Shutdown() override;

private:

	Brahmanda::TextureHandle TestTex;
	Brahmanda::TextureHandle TestTex1;
	Brahmanda::TextureHandle TestTex2;
	Brahmanda::TextureHandle TestTex3;
	std::unique_ptr<Brahmanda::AssetManager> Manager;
};