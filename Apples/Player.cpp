#include "Player.h"
#include "Constants.h"
#include "Game.h"
#include "Math.h"

namespace ApplesGame {
	// �������������� ������
	void InitPlayer(Player& player, const Game& game)
	{
		player.numEatenApples = 0;
		player.position = { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f };
		player.speed = INITIAL_SPEED;
		player.direction = PlayerDirection::Right;
		player.sprite.setTexture(game.playerTexture);
		SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
		SetSpriteRelativeOrigin(player.sprite, 0.5f, 0.5f);
	}

	// ��������� ������� ������
	void UpdatePlayer(Player& player, float deltaTime)
	{
		switch (player.direction)
		{
			case PlayerDirection::Right:
			{
				player.position.x += player.speed * deltaTime;
				break;
			}
			case PlayerDirection::Up:
			{
				player.position.y -= player.speed * deltaTime;
				break;
			}
			case PlayerDirection::Left:
			{
				player.position.x -= player.speed * deltaTime;
				break;
			}
			case PlayerDirection::Down:
			{
				player.position.y += player.speed * deltaTime;
				break;
			}
		}
	}

	// ������ ������
	void DrawPlayer(Player& player, sf::RenderWindow& window)
	{
		player.sprite.setPosition(player.position.x, player.position.y);
		window.draw(player.sprite);

		// Orient player sprite according to player direction
		if (player.direction == PlayerDirection::Left)
		{
			SetSpriteSize(player.sprite, -PLAYER_SIZE, PLAYER_SIZE);
			player.sprite.setRotation(0.f);
		}
		else
		{
			SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
			player.sprite.setRotation((float)player.direction * -90.f);
		}
	}

	sf::FloatRect GetPlayerCollider(const Player& player)
	{
		return { { player.position.x - PLAYER_SIZE / 2.f, player.position.y - PLAYER_SIZE / 2.f },
			{ PLAYER_SIZE, PLAYER_SIZE } };
	}

	void SetPlayerSpeed(Player& player, float speed)
	{
		player.speed = speed;
	}

	float GetPlayerSpeed(const Player& player)
	{
		return player.speed;
	}
}