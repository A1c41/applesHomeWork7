#include "TableOfRecords.h"
#include "Game.h"

namespace ApplesGame {
	bool PlayerExistsInTable(const std::set<PlayerDataForRecords, TableOfRecordsCompare>& players, const std::string& playerName) {
		return std::any_of(players.begin(), players.end(), [&playerName](const PlayerDataForRecords& playerData) {
			return playerData.playerName == playerName;
			});
	}

	// ������������� ������� ��������
	void InitTableOfRecords(Game& game)
	{
		game.tableOfRecords.background.setFillColor(sf::Color::Red); // ������������� ���� ���� ����
		game.tableOfRecords.background.setSize({ game.screenRect.width, game.screenRect.height });
		game.tableOfRecords.background.setPosition({ 0.f, 0.f });
		
		game.tableOfRecords.description.setFont(game.font); // ������������� �����
		game.tableOfRecords.description.setFillColor(sf::Color::White); // ������������� ���� ������
		game.tableOfRecords.description.setString(game.tableOfRecords.textDescription); // ������������� �����
		game.tableOfRecords.description.setPosition({ 5.f, 5.f }); // ������������� ������� ������ �� �������� ������

		game.tableOfRecords.tableOfRecords.setFont(game.font);
		game.tableOfRecords.tableOfRecords.setFillColor(sf::Color::White);
		sf::Vector2f tempLocal = game.tableOfRecords.description.getPosition();
		game.tableOfRecords.tableOfRecords.setPosition(tempLocal.x, tempLocal.y + 100);

		game.tableOfRecords.playersForTable.insert({"Player", game.player.numEatenApples});
		int i = 0;
		while (i < NUMBER_OF_PLAYER - 1) {
			std::string currentName = PLAYERS_NAMES[GetRandomIndex(PLAYERS_NAMES->size())];
			if (!PlayerExistsInTable(game.tableOfRecords.playersForTable, currentName)) {
				game.tableOfRecords.playersForTable.insert({ currentName, GetRandomIndex(30) });
				++i;
			}
		}
	}

	// ��������� ������� ��������
	void UpdateTableOfRecords(Game& game)
	{
		if (game.gameWindowEvent.type == sf::Event::KeyPressed)
		{
			if (game.gameWindowEvent.key.code == sf::Keyboard::Num1)
			{
				RestartGame(game); // ���������� ����� ����
			}
		}
	}

	// ������� �� ������ ������ � ������� �������� � ���������� ��� �����
	void SetPlayerScoreInTableOfRecords(Game& game)
	{
		// ����� �������� �� �����
		auto it = std::find_if(game.tableOfRecords.playersForTable.begin(), game.tableOfRecords.playersForTable.end(),
			[](const PlayerDataForRecords& record) {
				return record.playerName == "Player";
			});

		if (it != game.tableOfRecords.playersForTable.end()) {
			PlayerDataForRecords updatedRecord = *it; // ����������� ��������� �������
			game.tableOfRecords.playersForTable.erase(it); // ������� ������ �������
			updatedRecord.valueScore = game.player.numEatenApples; // �������� ��������
			game.tableOfRecords.playersForTable.insert(updatedRecord); // �������� ����������� �������
		}
	}

	// ������������� ��� ������ � ��� ���� � sf::Text ��� �����������
	void SetTableOfRecords(TableOfRecords& tableOfRecords)
	{
		std::string tempString = "";
		for (auto it : tableOfRecords.playersForTable)
		{
			tempString += "\n" + it.playerName + "	" + std::to_string(it.valueScore);
		}
		tableOfRecords.tableOfRecords.setString(tempString);
	}

	// ������������ ����
	void DrawTableOfRecords(Game& game, sf::RenderWindow& window)
	{
		window.draw(game.tableOfRecords.background);
		window.draw(game.tableOfRecords.description);
		window.draw(game.tableOfRecords.tableOfRecords);
	}
}