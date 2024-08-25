#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"

namespace ApplesGame {
	struct Game;

	enum class PlayerDirection {
		Right,
		Up,
		Down,
		Left
	};

	struct Player {
		sf::Vector2f position;
		PlayerDirection direction;
		float speed = INITIAL_SPEED;
		sf::Sprite sprite;
		int numEatenApples;
	};

	void InitPlayer(Player& player, const Game& game);
	void UpdatePlayer(Player& player, float deltaTime);
	void DrawPlayer(Player& player, sf::RenderWindow& window);
	sf::FloatRect GetPlayerCollider(const Player& player);
	void SetPlayerSpeed(Player& player, float speed);
	float GetPlayerSpeed(const Player& player);
}