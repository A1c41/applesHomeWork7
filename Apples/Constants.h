#pragma once
#include <string>

namespace ApplesGame {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const float INITIAL_SPEED = 100.f;
	const float PLAYER_SIZE = 20.f;
	const float APPLE_SIZE = 20.f;
	const float ACCELERATION = 20.f;
	const int NUM_ROCKS = 10;
	const float ROCK_SIZE = 15.f;
	const std::string RESOURCES_PATH = "Resources/";

	const int NUMBER_OF_PLAYER = 5; // Количество игроков в таблице рекордов
	// Список имен игроков
	const std::string PLAYERS_NAMES[20] = {
			"Oliver",
			"Jack",
			"Harry",
			"Jacob",
			"Charlie",
			"Thomas",
			"Oscar",
			"William",
			"James",
			"George",
			"Amelia",
			"Olivia",
			"Emily",
			"Ava",
			"Jessica",
			"Isabella",
			"Sophie",
			"Mia",
			"Ruby",
			"Lily"
	};
}