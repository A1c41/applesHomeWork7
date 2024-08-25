#include "Menu.h"
#include "Game.h"

namespace ApplesGame {
	// �������������� ����
	void InitMenu(Game& game) 
	{
		game.menu.background.setFillColor(sf::Color::Cyan); // ������������� ���� ���� ����
		game.menu.background.setSize({ game.screenRect.width, game.screenRect.height });
		game.menu.background.setPosition({ 0.f, 0.f });

		game.menu.description.setFont(game.font); // ������������� �����
		game.menu.description.setFillColor(sf::Color::Black); // ������������� ���� ������
		game.menu.description.setString(game.menu.textDescription); // ������������� �����
		sf::FloatRect descriptionSize = game.menu.description.getLocalBounds(); // �������� ������� ������������� ������
		game.menu.description.setOrigin({ descriptionSize.width / 2.f, descriptionSize.height / 2.f }); // ������������� ����� � ������
		game.menu.description.setPosition({ SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f }); // ������������� ������� ������ �� �������� ������
	}

	// ��������� ����
	void UpdateMenu(Game& game)
	{
		if (game.gameWindowEvent.type == sf::Event::KeyPressed)
		{
			if (game.gameWindowEvent.key.code == sf::Keyboard::Num4)
			{
				game.gameStates.push(GameStates::ExitGame);
			}
			if (game.gameWindowEvent.key.code == sf::Keyboard::Num3)
			{
				SetPlayerScoreInTableOfRecords(game);
				SetTableOfRecords(game.tableOfRecords);
				game.gameStates.push(GameStates::TableOfRecords);
			}
			if (game.gameWindowEvent.key.code == sf::Keyboard::Num2)
			{
				game.gameStates.push(GameStates::Settings);
			}
			if (game.gameWindowEvent.key.code == sf::Keyboard::Num1)
			{
				game.gameStates.push(GameStates::GameStart);
			}
		}
	}

	// ������������ ����
	void DrawMenu(Game& game, sf::RenderWindow& window)
	{
		window.draw(game.menu.background);
		window.draw(game.menu.description);
	}
}