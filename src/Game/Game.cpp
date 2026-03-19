// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#include "Game.h"
#include "Engine/Framework/AssetManager.h"
#include "Engine/Framework/Logger.h"

//...

Game::Game()
{

}

bool Game::Init()
{
	Logger::Info("Game Initialized!");
	TestTex = Manager->ReqLoadTexture(RESOURCE_DIR "dirt.png");
	TestTex1 = Manager->ReqLoadTexture(RESOURCE_DIR "dirt.png");
	TestTex2 = Manager->ReqLoadTexture(RESOURCE_DIR "dirt.png");
	TestTex3 = Manager->ReqLoadTexture(RESOURCE_DIR "dirt.png");

	return false;
}

void Game::Cycle(float DeltaTime)
{
	static float PosX = 500.f;
	static float PosY = 500.f;

	if (Texture* Tex = Manager->GetTexture(TestTex))
	{
		DrawTexturePro(*Tex, { 0, 0, (float)Tex->width, (float)Tex->height }, { 50, 50, 100, 100 }, {}, 0, WHITE);
	}

	if (IsKeyDown(KEY_W))
	{
		PosY += -1 * 100 * DeltaTime;
		TestTex.ReleaseHandle();
		//Manager->ReqUnloadTexture(TestTex);
	}
	if (IsKeyDown(KEY_S))
	{
		PosY += 1 * 100 * DeltaTime;

		if (Texture* Tex = Manager->GetTexture(TestTex1))
		{
			DrawTexturePro(*Tex, { 0, 0, (float)Tex->width, (float)Tex->height }, { 150, 150, 100, 100 }, {}, 0, WHITE);
		}
	}
	if (IsKeyDown(KEY_D))
	{
		PosX += 1 * 100 * DeltaTime;
	}
	if (IsKeyDown(KEY_A))
	{
		PosX += -1 * 100 * DeltaTime;
	}

	DrawRectangle(PosX, PosY, 120, 120, DARKBLUE);
	DrawRectangle(500, 500, 120, 120, DARKPURPLE);
	DrawText("This is the Beginning of Brahmanda Engine!", 190, 200, 20, DARKBLUE);

#pragma region ImGui

	//Enabling docking with main window
	ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
	ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
	ImGui::DockSpaceOverViewport(0U, ImGui::GetMainViewport());
	ImGui::PopStyleColor(2);

	ImGui::Begin("Brahmanda Test");

	ImGui::Text("Hello from ImGui Brahmanda");

	if (ImGui::Button("Interact"))
	{
		spdlog::info("Interaction Success!");
	}

	ImGui::ShowDemoWindow();

	ImGui::End();

	ImGui::Begin("Brahmanda Options");

	ImGui::Text("This is options window");
	ImGui::Separator();
	ImGui::NewLine();
	static float SliderVal1 = 0.f;
	ImGui::SliderFloat("Some Slider", &SliderVal1, 0.f, 1.f);

	ImGui::End();

#pragma endregion

}

void Game::Shutdown()
{
	//UnloadTexture(TestTexture);
}

void Game::SetAssetManager(Brahmanda::AssetManager* InMgr)
{
	Manager = InMgr;
}

Game::~Game()
{

}