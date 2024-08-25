#pragma once
#include "Constants.h"
#include "Player.h"
#include "Menu.h"
#include "GameStart.h"
#include "Pause.h"
#include "Apple.h"
#include "Rock.h"
#include "Math.h"
#include "TableOfRecords.h"
#include "Sound.h"
#include "Settings.h"
#include <vector>
#include <stack>
#include <unordered_set>

namespace ApplesGame {
	enum class GameStates {
		GameStart = 1, // Игра играется
		Pause = 2, // Пауза с меню
		Menu = 3, // Меню в начале игры
		TableOfRecords = 4, // Таблица рекордов после проигрыша
		ExitGame = 5, // Закрываем игру
		Settings = 6, // Настройки
		RestartGame = 7, // Перезапуск игры
	};

	struct Game {
		std::stack<GameStates> gameStates; // Храним текущее игровое состояние

		// Игровой фон
		sf::FloatRect screenRect;
		sf::RectangleShape background;

		// Количество яблок на карте
		int numApples = GetRandomNumApple();

		// Игровые объекты
		// Игрок
		Player player; 
		// Яблоки
		Apple apple;
		std::unordered_set<Apple, AppleHash> apples;
		// Камни
		Rock rock;
		std::vector<Rock> rocks;

		// Игровые ресурсы
		sf::Texture playerTexture;
		sf::Texture appleTexture;
		sf::Texture rockTexture;
		sf::Font font;
		Sound sound;
		
		// Игровые состояния
		Menu menu;
		Pause pause;
		GameStart gameStart;
		TableOfRecords tableOfRecords;
		GameSettings gameSettings;

		// Ивенты окна
		sf::Event gameWindowEvent;
	};

	void InitGame(Game& game);
	void UpdateGame(Game& game, float deltaTime);
	void DrawGame(Game& game, sf::RenderWindow& window);
	void RestartGame(Game& game);
}