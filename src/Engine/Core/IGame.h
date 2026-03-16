// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include "CoreIncludes.h"

namespace Brahmanda
{
	class IGame
	{
	public:

		virtual ~IGame() = default;

		virtual bool InitGame() = 0;
		virtual void CycleGame() = 0;
		virtual void ShutdownGame() = 0;
	};
}