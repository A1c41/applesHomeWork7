#pragma once
#include "SFML\Graphics.hpp"

namespace ApplesGame {
	struct Game;

	struct Pause {
		sf::Text description; // ����� ������� ����� ������������
		std::string textDescription; // �����, ������� ����� ����������� �������������
		sf::RectangleShape background; // ��� �����
	};

	void InitPause(Game& game);
	void UpdatePause(Game& game);
	void DrawPause(Game& game, sf::RenderWindow& window);
}