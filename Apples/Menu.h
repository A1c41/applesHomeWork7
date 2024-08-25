#pragma once
#include "SFML\Graphics.hpp"

namespace ApplesGame {
	struct Game;

	struct Menu {
		sf::Text description; // Текст который будет отображаться
		std::string textDescription; // Текст, который будем присваивать отображаемому
		sf::RectangleShape background; // Фон меню
	};

	void InitMenu(Game& game);
	void UpdateMenu(Game& game);
	void DrawMenu(Game& game, sf::RenderWindow& window);
}