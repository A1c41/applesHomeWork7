#pragma once
#include "SFML/Graphics.hpp"

namespace ApplesGame {
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);
	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);
	int GetRandomNumApple(); // Рандомное количество яблок
	sf::Vector2f GetRandomPositionOnScreen(sf::FloatRect rect);
	bool DoShapesCollide(const sf::FloatRect& rect1, const sf::FloatRect& rect2);
	int GetRandomIndex(int maxValue);
}