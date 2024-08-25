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
		GameStart = 1, // ���� ��������
		Pause = 2, // ����� � ����
		Menu = 3, // ���� � ������ ����
		TableOfRecords = 4, // ������� �������� ����� ���������
		ExitGame = 5, // ��������� ����
		Settings = 6, // ���������
		RestartGame = 7, // ���������� ����
	};

	struct Game {
		std::stack<GameStates> gameStates; // ������ ������� ������� ���������

		// ������� ���
		sf::FloatRect screenRect;
		sf::RectangleShape background;

		// ���������� ����� �� �����
		int numApples = GetRandomNumApple();

		// ������� �������
		// �����
		Player player; 
		// ������
		Apple apple;
		std::unordered_set<Apple, AppleHash> apples;
		// �����
		Rock rock;
		std::vector<Rock> rocks;

		// ������� �������
		sf::Texture playerTexture;
		sf::Texture appleTexture;
		sf::Texture rockTexture;
		sf::Font font;
		Sound sound;
		
		// ������� ���������
		Menu menu;
		Pause pause;
		GameStart gameStart;
		TableOfRecords tableOfRecords;
		GameSettings gameSettings;

		// ������ ����
		sf::Event gameWindowEvent;
	};

	void InitGame(Game& game);
	void UpdateGame(Game& game, float deltaTime);
	void DrawGame(Game& game, sf::RenderWindow& window);
	void RestartGame(Game& game);
}