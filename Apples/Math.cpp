#include "Math.h"

namespace ApplesGame {
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sf::Vector2f scale = { desiredWidth / spriteRect.width, desiredHeight / spriteRect.height };
		sprite.setScale(scale);
	}

	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}

	int GetRandomNumApple()
	{
		return (rand() % 20 + 1);
	}

	sf::Vector2f GetRandomPositionOnScreen(sf::FloatRect rect)
	{
		sf::Vector2f result;
		result.x = rand() / (float)RAND_MAX * rect.width + rect.top;
		result.y = rand() / (float)RAND_MAX * rect.height + rect.left;
		return result;
	}

	bool DoShapesCollide(const sf::FloatRect& rect1, const sf::FloatRect& rect2)
	{
		return rect1.left < rect2.left + rect2.width &&
			rect1.left + rect1.width > rect2.left &&
			rect1.top < rect2.top + rect2.height &&
			rect1.top + rect1.height > rect2.top;
	}

	int GetRandomIndex(int maxValue)
	{
		return rand() % maxValue;
	}
}