#pragma once
#include "SFML\Graphics.hpp"
#include "Constants.h"
#include <set>

namespace ApplesGame {
	struct Game;

	struct PlayerDataForRecords {
		std::string playerName; // ��� ������
		int valueScore = 0; // ���� ������
	};

	struct TableOfRecordsCompare {
		bool operator()(PlayerDataForRecords a, PlayerDataForRecords b) const {
			return a.valueScore > b.valueScore;
		}
	};

	struct TableOfRecords {
		sf::Text description; // ����� ������� ����� ������������
		sf::Text tableOfRecords; // ���� ������� ��������
		std::string textDescription; // �����, ������� ����� ����������� �������������
		sf::RectangleShape background; // ��� ������� ��������
		std::set<PlayerDataForRecords, TableOfRecordsCompare> playersForTable;
	};

	void InitTableOfRecords(Game& game);
	void UpdateTableOfRecords(Game& game);
	void SetPlayerScoreInTableOfRecords(Game& game);
	void SetTableOfRecords(TableOfRecords& tableOfRecords);
	void DrawTableOfRecords(Game& game, sf::RenderWindow& window);
}