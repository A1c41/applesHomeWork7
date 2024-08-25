#include "Apple.h"
#include "Game.h"

namespace ApplesGame {
	Apple InitApple(Apple& apple, Game& game)
	{
		apple.sprite.setTexture(game.appleTexture);
		SetSpriteSize(apple.sprite, APPLE_SIZE, APPLE_SIZE);
		SetSpriteRelativeOrigin(apple.sprite, 0.5f, 0.5f);
		apple.position = GetRandomPositionOnScreen(game.screenRect);

		return apple;
	}

	void DrawApple(Apple& apple, sf::RenderWindow& window)
	{
		apple.sprite.setPosition(apple.position.x, apple.position.y);
		window.draw(apple.sprite);
	}

	sf::FloatRect GetAppleCollider(const Apple& apple)
	{
		return { { apple.position.x - APPLE_SIZE / 2.f, apple.position.y - APPLE_SIZE / 2.f },
			{ APPLE_SIZE, APPLE_SIZE } };
	}

	void SetApplePosition(Apple& apple, sf::Vector2f position) 
	{
		apple.isEaten = false;
		apple.position = position;
	}

	// Проверяем, все ли яблоки съедены
	bool IsAllApplesEaten(Game& game) {
		for (auto apple : game.apples)
		{
			if (!apple.isEaten)
			{
				return true;
			}
		}
		return false;
	}
}