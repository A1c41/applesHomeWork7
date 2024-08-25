#include "GameStart.h"
#include "Game.h"

namespace ApplesGame {
	// ������������� ��������� ��� �������� ����
	void InitGameWindow(Game& game)
	{
		game.gameStart.background.setFillColor(sf::Color::Black);
		game.gameStart.description.setFont(game.font);
		game.gameStart.description.setString(game.gameStart.textDescription);
		game.gameStart.description.setPosition(5.f, 5.f);
	}

	// ��������� ��������
	void CheckAppleCollide(Game& game)
	{
		std::vector<Apple> updatedApples;
		for (auto apple : game.apples) // ����������� �������� ��� ���������
		{
			if (DoShapesCollide(GetPlayerCollider(game.player), GetAppleCollider(apple)))
			{
				if (game.gameSettings.setMask & Settings::FinalApples) {
					apple.isEaten = true;
					apple.position = { -100, -100 };
					
				}
				else {
					apple.position = GetRandomPositionOnScreen(game.screenRect); // ������ ����������� �������
				}

				// ��������� ������ �����
				++game.player.numEatenApples;

				// ���� �������� ��������� ��������� ������, �� ���������� ���������, ����� �������� �� �������
				game.gameSettings.setMask& Settings::WithoutAccelerationPlayer
					? SetPlayerSpeed(game.player, GetPlayerSpeed(game.player))
					: SetPlayerSpeed(game.player, GetPlayerSpeed(game.player) + ACCELERATION);

				game.sound.eatSound.play();

				// ��������� ����� �����
				game.gameStart.description.setString(game.gameStart.textDescription + std::to_string(game.player.numEatenApples));
			}
			updatedApples.push_back(apple);
		}

		// ��������� ������������ ���������
		game.apples.clear();
		for (const auto& apple : updatedApples) {
			game.apples.insert(apple);
		}

		if (!IsAllApplesEaten(game)) {
			SetPlayerScoreInTableOfRecords(game);
			SetTableOfRecords(game.tableOfRecords);
			game.gameStates.pop();
			game.gameStates.push(GameStates::TableOfRecords);
		}
	}

	// ��������� �������� � ��������� ������
	void CheckScreenCollide(Game& game)
	{
		if (!DoShapesCollide(GetPlayerCollider(game.player), game.screenRect))
		{
			SetPlayerScoreInTableOfRecords(game);
			SetTableOfRecords(game.tableOfRecords);
			game.sound.deathSound.play();
			game.gameStates.pop();
			game.gameStates.push(GameStates::TableOfRecords);
		}
	}

	// �������� �������� � �������
	void CheckRockCollide(Game& game)
	{
		for (int i = 0; i < NUM_ROCKS; ++i)
		{
			if (DoShapesCollide(GetPlayerCollider(game.player), GetRockCollider(game.rocks[i])))
			{
				SetPlayerScoreInTableOfRecords(game);
				SetTableOfRecords(game.tableOfRecords);
				game.sound.deathSound.play();
				game.gameStates.pop();
				game.gameStates.push(GameStates::TableOfRecords);
			}
		}
	}

	// ��������� ����
	void UpdateGameObject(Game& game, float deltaTime)
	{
		// ��������� ���� � ����������
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			game.player.direction = PlayerDirection::Left;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			game.player.direction = PlayerDirection::Up;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			game.player.direction = PlayerDirection::Right;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			game.player.direction = PlayerDirection::Down;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			game.gameStates.push(GameStates::Pause);
		}

		InitGameWindow(game);
		UpdatePlayer(game.player, deltaTime);
		CheckAppleCollide(game);
		CheckScreenCollide(game);
		CheckRockCollide(game);

		game.gameStart.description.setString(game.gameStart.textDescription + std::to_string(game.player.numEatenApples));
	}

	// ������ ������� �������
	void DrawGameObject(Game& game, sf::RenderWindow& window) {
		window.draw(game.gameStart.background);
		window.draw(game.gameStart.description);
		
		DrawPlayer(game.player, window);

		for (auto apple : game.apples)
		{
			DrawApple(apple, window);
		}

		for (int i = 0; i < NUM_ROCKS; ++i) {
			DrawRock(game.rocks[i], window);
		}
	}
}