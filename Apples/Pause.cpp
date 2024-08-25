#include "Pause.h"
#include "Game.h"

namespace ApplesGame {
	// �������������� ���� �����
	void InitPause(Game& game)
	{
		game.pause.background.setFillColor(sf::Color::Magenta);
		game.pause.background.setSize({ game.screenRect.width, game.screenRect.height });
		game.pause.background.setPosition({ 0.f, 0.f });

		game.pause.description.setFont(game.font); // ������������� �����
		game.pause.description.setFillColor(sf::Color::Black); // ������������� ���� ������
		game.pause.description.setString(game.pause.textDescription); // ������������� �����
		sf::FloatRect descriptionSize = game.pause.description.getLocalBounds(); // �������� ������� ������������� ������
		game.pause.description.setOrigin({ descriptionSize.width / 2.f, descriptionSize.height / 2.f }); // ������������� ����� � ������
		game.pause.description.setPosition({ SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f }); // ������������� ������� ������ �� �������� ������
	}

	// ��������� ���� �����
	void UpdatePause(Game& game)
	{
		if (game.gameWindowEvent.type == sf::Event::KeyPressed)
		{
			if (game.gameWindowEvent.key.code == sf::Keyboard::Num3) // ����� �� ����
			{
				game.gameStates.push(GameStates::ExitGame); // ������� �� ����
			}
			if (game.gameWindowEvent.key.code == sf::Keyboard::Num2) // ������� ������� ����
			{
				RestartGame(game); // ����� ������� ����
			}
			if (game.gameWindowEvent.key.code == sf::Keyboard::Num1) // ���������� ������
			{
				game.gameStates.pop(); // ���������� ��������� GameStart
			}
		}
	}

	// ������ ���� �����
	void DrawPause(Game& game, sf::RenderWindow& window)
	{
		window.draw(game.pause.background);
		window.draw(game.pause.description);
	}
}