#include "Settings.h"
#include "Constants.h"
#include <cassert>
#include "Game.h"

namespace ApplesGame {
	void InitSettings(Game& game)
	{
		game.gameSettings.background.setFillColor(sf::Color::Green); // Устанавливаем цвет фона меню
		game.gameSettings.background.setSize({ game.screenRect.width, game.screenRect.height });
		game.gameSettings.background.setPosition({ 0.f, 0.f });

		game.gameSettings.description.setFont(game.font); // Устанавливаем шрифт
		game.gameSettings.description.setFillColor(sf::Color::Black); // Устанавливаем цвет шрифта
		game.gameSettings.description.setString(game.gameSettings.textDescription); // Устанавливаем текст
		//sf::FloatRect tempDescriptionSize = game.gameSettings.description.getLocalBounds(); // Получаем размеры получившегося текста
		//game.gameSettings.description.setOrigin({ tempDescriptionSize.width / 2.f, tempDescriptionSize.height / 2.f }); // Устанавливаем центр у текста
		game.gameSettings.description.setPosition({ /*SCREEN_WIDTH / 2.f*/10.f, /*SCREEN_HEIGHT / 2.f*/10.f }); // Устанавливаем позицию текста по середине экрана

		game.gameSettings.currentSettings.setFont(game.font);
		game.gameSettings.currentSettings.setFillColor(sf::Color::Black);
		game.gameSettings.currentSettings.setString(game.gameSettings.inputSettings);
		sf::FloatRect tempPosition = game.gameSettings.description.getLocalBounds();
		game.gameSettings.currentSettings.setPosition({ 10.f, tempPosition.height + 10.f});
	}

    void UpdateSettings(Game& game)
    {
        // Проверяем, есть ли событие
        if (game.gameWindowEvent.type == sf::Event::KeyPressed)
        {
            if (game.gameWindowEvent.key.code == sf::Keyboard::Num0)
            {
                game.gameStates.pop();
            }
            else if (game.gameWindowEvent.key.code == sf::Keyboard::Num1)
            {
                if (!(game.gameSettings.setMask & Settings::FinalApples))
                {
                    game.gameSettings.setMask |= static_cast<int>(Settings::FinalApples);
                    game.gameSettings.inputSettings += std::to_string(static_cast<int>(Settings::FinalApples));
                    game.gameSettings.currentSettings.setString(game.gameSettings.inputSettings);
                }
            }
            else if (game.gameWindowEvent.key.code == sf::Keyboard::Num2)
            {
                if (!(game.gameSettings.setMask & Settings::WithoutAccelerationPlayer))
                {
                    game.gameSettings.setMask |= static_cast<int>(Settings::WithoutAccelerationPlayer);
                    game.gameSettings.inputSettings += std::to_string(static_cast<int>(Settings::WithoutAccelerationPlayer));
                    game.gameSettings.currentSettings.setString(game.gameSettings.inputSettings);
                }
            }
            else if (game.gameWindowEvent.key.code == sf::Keyboard::BackSpace)
            {
                // Очищаем настройки
                game.gameSettings.setMask = 0;
                game.gameSettings.inputSettings = "";
                game.gameSettings.currentSettings.setString("");
            }
        }
    }


	void DrawSettings(Game& game, sf::RenderWindow& window) 
	{
		window.draw(game.gameSettings.background);
		window.draw(game.gameSettings.description);
		window.draw(game.gameSettings.currentSettings);
	}
}

