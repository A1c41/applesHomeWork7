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
		sf::Text description; // ����� ������� ����� ������������
		sf::Text currentSettings; // ������� ��������� ���� ��� ��������� �� ������
		std::string textDescription; // �����, ������� ����� ����������� �������������
		sf::RectangleShape background; // ��� ��������

		std::string inputSettings = ""; // ������� ��������� ��� ����������� ������
	};

	void InitSettings(Game& game);
	void UpdateSettings(Game& game);
	void DrawSettings(Game& game, sf::RenderWindow& window);
}