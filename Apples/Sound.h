#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

namespace ApplesGame {
	struct Game;

	struct Sound{
		sf::Sound eatSound;
		sf::Sound deathSound;

		sf::SoundBuffer eatBuffer;
		sf::SoundBuffer deathBuffer;
	};

	void InitSound(Sound& sound);
}