#include "Rock.h"
#include "Game.h"

namespace ApplesGame {
	Rock InitRock(Rock& rock, Game& game)
	{
		rock.sprite.setTexture(game.rockTexture);
		SetSpriteSize(rock.sprite, ROCK_SIZE, ROCK_SIZE);
		SetSpriteRelativeOrigin(rock.sprite, 0.5f, 0.5f);
		rock.position = GetRandomPositionOnScreen(game.screenRect);

		return rock;
	}

	void DrawRock(Rock& rock, sf::RenderWindow& window)
	{
		rock.sprite.setPosition(rock.position.x, rock.position.y);
		window.draw(rock.sprite);
	}

	sf::FloatRect GetRockCollider(const Rock& rock)
	{
		return { { rock.position.x - ROCK_SIZE / 2.f, rock.position.y - ROCK_SIZE / 2.f },
			{ ROCK_SIZE, ROCK_SIZE } };
	}

	void SetRockPosition(Rock& rock, sf::Vector2f position)
	{
		rock.position = position;
	}
}