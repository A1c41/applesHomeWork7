#pragma once
#include "SFML\Graphics.hpp"
#include "Math.h"

namespace ApplesGame {
	struct Game;

	struct Rock {
		sf::Vector2f position;
		sf::Sprite sprite;
	};

	Rock InitRock(Rock& rock, Game& game);
	void DrawRock(Rock& rock, sf::RenderWindow& window);
	void SetRockPosition(Rock& rock, sf::Vector2f position);
	sf::FloatRect GetRockCollider(const Rock& rock);
}