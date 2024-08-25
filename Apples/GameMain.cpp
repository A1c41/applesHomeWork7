#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"

int main()
{
	using namespace ApplesGame;


	int seed = (int)time(nullptr);
	srand(seed);
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Apples Game!");

	Game game;
	InitGame(game); // Инициализируем игровые объекты

	while (window.isOpen())
	{
		sf::sleep(sf::milliseconds(16));

		// Calculate time delta
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		while (window.pollEvent(game.gameWindowEvent))
		{
			if (game.gameWindowEvent.type == sf::Event::Closed)
				window.close();

			// Обрабатываем события в зависимости от состояния игры
			switch (game.gameStates.top())
			{
			case GameStates::Menu:
				UpdateMenu(game);
				break;
			case GameStates::Pause:
				UpdatePause(game);
				break;
			case GameStates::TableOfRecords:
				UpdateTableOfRecords(game);
				break;
			case GameStates::Settings:
				UpdateSettings(game);
				break;
			}
		}

		// Обновляем игру
		UpdateGame(game, deltaTime);

		if (game.gameStates.top() == GameStates::ExitGame) {
			window.close();
		}

		window.clear();
		DrawGame(game, window);
		//window.draw(game.background);
		window.display();
	}

	return 0;
}
