#include "Game.h"
#include <cassert>

namespace ApplesGame {
	// Инициализация начальных игровых объектов при запуске игры
	void InitGame(Game& game)
	{
		// Устанавливаем начальное состояние игры
		game.gameStates.push(GameStates::Menu);

		// Задаем размеры экрана
		game.screenRect = { 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT };

		// Загружаем все текстуры и шрифты
		assert(game.font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Roboto-Bold.ttf"));
		assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "\\Player.png"));
		assert(game.appleTexture.loadFromFile(RESOURCES_PATH + "\\Apple.png"));
		assert(game.rockTexture.loadFromFile(RESOURCES_PATH + "\\Rock.png"));
		assert(game.sound.deathBuffer.loadFromFile(RESOURCES_PATH + "\\Death.wav"));
		assert(game.sound.eatBuffer.loadFromFile(RESOURCES_PATH + "\\AppleEat.wav"));

		// Устанавливаем текста
		game.menu.textDescription = "Game \"Apples\"\n\nMenu control:\n1 - Start the game.\n2 - Game settings.\n3 - Open table of records.\n4 - Exit the game.";
		game.pause.textDescription = "Game \"Apples\"\n\nPause control:\n1 - Continue the game.\n2 - Open main menu.\n3 - Exit the game.";
		game.gameStart.textDescription = "Score ";
		game.tableOfRecords.textDescription = "Table of records\nPress:\n1 - Open main menu.\n";
		game.gameSettings.textDescription = "Description of game settings\n(enter the number of the corresponding settings):\n1 - final apples;\n2 - without player acceleration.\n0 - accept the settings and start the game.\nBackSpace - clear settings.";

		// Инициализация игровых объектов
		InitPlayer(game.player, game);
		
		for (int i = 0; i < game.numApples; ++i) 
		{
			game.apples.insert(InitApple(game.apple, game));
		}

		for (int i = 0; i < NUM_ROCKS; ++i)
		{
			game.rocks.push_back(InitRock(game.rock, game));
		}

		// Инициализируем игровые экраны
		InitMenu(game);
		InitPause(game);
		InitGameWindow(game);
		InitTableOfRecords(game);
		InitSettings(game);
		InitSound(game.sound);
	}

	void RestartStack(Game& game)
	{
		while (!game.gameStates.empty())
		{
			game.gameStates.pop();
		}
	}

	// Перезапуск игры
	void RestartGame(Game& game)
	{
		RestartStack(game); // Сбрасываем стек
		game.gameStates.push(GameStates::Menu); // Устанавливаем состояние Menu

		InitPlayer(game.player, game);

		std::vector<Apple> updatedApples;
		for (auto apple : game.apples)
		{
			SetApplePosition(apple, GetRandomPositionOnScreen(game.screenRect));
			updatedApples.push_back(apple);
		}
		game.apples.clear();
		for (const auto& apple : updatedApples) {
			game.apples.insert(apple);
		}

		for (int i = 0; i < NUM_ROCKS; ++i)
		{
			SetRockPosition(game.rocks[i], GetRandomPositionOnScreen(game.screenRect));
		}
	}

	// Обновляем игру в зависимости от ее состояния
	void UpdateGame(Game& game, float deltaTime)
	{
		switch (game.gameStates.top()) 
		{
			case GameStates::GameStart:
			{
				UpdateGameObject(game, deltaTime);
				break;
			}
		}
	}

	// Рисуем игру
	void DrawGame(Game& game, sf::RenderWindow& window)
	{
		switch (game.gameStates.top()) {
			case GameStates::Menu:
			{
				DrawMenu(game, window);
				break;
			}
			case GameStates::GameStart:
			{
				DrawGameObject(game, window);
				break;
			}
			case GameStates::Pause:
			{
				DrawPause(game, window);
				break;
			}
			case GameStates::TableOfRecords:
			{
				DrawTableOfRecords(game, window);
				break;
			}
			case GameStates::Settings:
			{
				DrawSettings(game, window);
				break;
			}
		}
	}
}