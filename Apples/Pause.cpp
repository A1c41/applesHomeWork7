#include "Pause.h"
#include "Game.h"

namespace ApplesGame {
	// Инициализируем окно паузы
	void InitPause(Game& game)
	{
		game.pause.background.setFillColor(sf::Color::Magenta);
		game.pause.background.setSize({ game.screenRect.width, game.screenRect.height });
		game.pause.background.setPosition({ 0.f, 0.f });

		game.pause.description.setFont(game.font); // Устанавливаем шрифт
		game.pause.description.setFillColor(sf::Color::Black); // Устанавливаем цвет шрифта
		game.pause.description.setString(game.pause.textDescription); // Устанавливаем текст
		sf::FloatRect descriptionSize = game.pause.description.getLocalBounds(); // Получаем размеры получившегося текста
		game.pause.description.setOrigin({ descriptionSize.width / 2.f, descriptionSize.height / 2.f }); // Устанавливаем центр у текста
		game.pause.description.setPosition({ SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f }); // Устанавливаем позицию текста по середине экрана
	}

	// Обновляем окно паузы
	void UpdatePause(Game& game)
	{
		if (game.gameWindowEvent.type == sf::Event::KeyPressed)
		{
			if (game.gameWindowEvent.key.code == sf::Keyboard::Num3) // Выход из игры
			{
				game.gameStates.push(GameStates::ExitGame); // Выходим из игры
			}
			if (game.gameWindowEvent.key.code == sf::Keyboard::Num2) // Открыть главное меню
			{
				RestartGame(game); // Сброс игровых стат
			}
			if (game.gameWindowEvent.key.code == sf::Keyboard::Num1) // Продолжаем играть
			{
				game.gameStates.pop(); // Возвращаем состояние GameStart
			}
		}
	}

	// Рисуем окно паузы
	void DrawPause(Game& game, sf::RenderWindow& window)
	{
		window.draw(game.pause.background);
		window.draw(game.pause.description);
	}
}