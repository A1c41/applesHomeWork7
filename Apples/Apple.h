#pragma once
#include "SFML\Graphics.hpp"
#include "Math.h"

namespace ApplesGame {
	struct Game;

	struct Apple {
		sf::Vector2f position;
		sf::Sprite sprite;
		bool isEaten = false;

		// Определяем оператор == для сравнения
		bool operator==(const Apple& other) const {
			return position == other.position && isEaten == other.isEaten;
		}
	};

	struct AppleHash {
		std::size_t operator()(const Apple& apple) const {
			// Хэшируем только позицию и isEaten
			std::size_t h1 = std::hash<float>{}(apple.position.x);
			std::size_t h2 = std::hash<float>{}(apple.position.y);
			std::size_t h3 = std::hash<bool>{}(apple.isEaten);
			return h1 ^ (h2 << 1) ^ (h3 << 2); // Комбинируем хэши
		}
	};

	Apple InitApple(Apple& apple, Game& game);
	void DrawApple(Apple& apple, sf::RenderWindow& window);
	sf::FloatRect GetAppleCollider(const Apple& apple);
	void SetApplePosition(Apple& apple, sf::Vector2f position);
	bool IsAllApplesEaten(Game& game);
}