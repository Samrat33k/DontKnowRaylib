// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "Application.h"
#include "Game/Game.h"

//...

int main()
{
	Brahmanda::Application App;
	Game MyGame;
	
	App.SetGame(&MyGame);
	if (App.InitApplication())
	{
		App.CycleApplication();
	}

	return 0;
}