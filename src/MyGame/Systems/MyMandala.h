// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "Engine/GameFramework/Mandala.h"
#include "Engine/GameFramework/WorldLayerCollection.h"

//...

class MyMandala : public Brahmanda::Mandala
{
public:

	MyMandala();
	virtual ~MyMandala() override;

	bool Init() override;
	void Cycle(float DeltaTime, Brahmanda::FrameContextData& InContext) override;
	void Shutdown() override;

private:

	Brahmanda::WorldLayerCollection<8> WorldLayers;
};