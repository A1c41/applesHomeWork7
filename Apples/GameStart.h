#pragma once
#include "SFML\Graphics.hpp"

namespace ApplesGame {
	struct Game;

	struct GameStart {
		sf::Text description; // ����� ������� ����� ������������
		std::string textDescription; // �����, ������� ����� ����������� �������������
		sf::RectangleShape background; // ��� �������� ����
	};

	void InitGameWindow(Game& game);
	void UpdateGameObject(Game& game, float deltaTime);
	void DrawGameObject(Game& game, sf::RenderWindow& window);
}