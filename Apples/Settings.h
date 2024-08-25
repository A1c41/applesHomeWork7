#pragma once
#include "SFML\Graphics.hpp"

namespace ApplesGame {
	struct Game;

	enum Settings {
		Empty = 0,
		FinalApples = 1 << 0,
		WithoutAccelerationPlayer = 1 << 1,
		StartGame,
		ClearSetting
	};

	struct GameSettings {
		int setMask = static_cast<int>(Settings::Empty);
		sf::Text description; // Текст который будет отображаться
		sf::Text currentSettings; // Текущие настройки игры для отрисовки на экране
		std::string textDescription; // Текст, который будем присваивать отображаемому
		sf::RectangleShape background; // Фон Настроек

		std::string inputSettings = ""; // Текущие настройки для отображения игроку
	};

	void InitSettings(Game& game);
	void UpdateSettings(Game& game);
	void DrawSettings(Game& game, sf::RenderWindow& window);
}