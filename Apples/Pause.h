#pragma once
#include "SFML\Graphics.hpp"

namespace ApplesGame {
	struct Game;

	struct Pause {
		sf::Text description; // Текст который будет отображаться
		std::string textDescription; // Текст, который будем присваивать отображаемому
		sf::RectangleShape background; // Фон паузы
	};

	void InitPause(Game& game);
	void UpdatePause(Game& game);
	void DrawPause(Game& game, sf::RenderWindow& window);
}