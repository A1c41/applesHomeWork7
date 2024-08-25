#pragma once
#include "SFML\Graphics.hpp"

namespace ApplesGame {
	struct Game;

	struct Menu {
		sf::Text description; // ����� ������� ����� ������������
		std::string textDescription; // �����, ������� ����� ����������� �������������
		sf::RectangleShape background; // ��� ����
	};

	void InitMenu(Game& game);
	void UpdateMenu(Game& game);
	void DrawMenu(Game& game, sf::RenderWindow& window);
}