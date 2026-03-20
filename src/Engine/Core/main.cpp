// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "Application.h"
#include "Game/Game.h"

//...

int main()
{
	Brahmanda::Application App;
	Brahmanda::Game MyGame;
	
	App.ManageGame(&MyGame);
	if (App.InitApplication())
	{
		App.StartApplicationCycle();
	}

	return 0;
}