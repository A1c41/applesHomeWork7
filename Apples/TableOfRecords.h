#pragma once
#include "SFML\Graphics.hpp"
#include "Constants.h"
#include <set>

namespace ApplesGame {
	struct Game;

	struct PlayerDataForRecords {
		std::string playerName; // Имя игрока
		int valueScore = 0; // Очки игрока
	};

	struct TableOfRecordsCompare {
		bool operator()(PlayerDataForRecords a, PlayerDataForRecords b) const {
			return a.valueScore > b.valueScore;
		}
	};

	struct TableOfRecords {
		sf::Text description; // Текст который будет отображаться
		sf::Text tableOfRecords; // Сама таблица рекордов
		std::string textDescription; // Текст, который будем присваивать отображаемому
		sf::RectangleShape background; // Фон таблицы рекордов
		std::set<PlayerDataForRecords, TableOfRecordsCompare> playersForTable;
	};

	void InitTableOfRecords(Game& game);
	void UpdateTableOfRecords(Game& game);
	void SetPlayerScoreInTableOfRecords(Game& game);
	void SetTableOfRecords(TableOfRecords& tableOfRecords);
	void DrawTableOfRecords(Game& game, sf::RenderWindow& window);
}