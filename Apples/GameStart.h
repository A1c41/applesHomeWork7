#pragma once
#include "SFML\Graphics.hpp"

namespace ApplesGame {
	struct Game;

	struct GameStart {
		sf::Text description; // Текст который будет отображаться
		std::string textDescription; // Текст, который будем присваивать отображаемому
		sf::RectangleShape background; // Фон игрового окна
	};

	void InitGameWindow(Game& game);
	void UpdateGameObject(Game& game, float deltaTime);
	void DrawGameObject(Game& game, sf::RenderWindow& window);
}