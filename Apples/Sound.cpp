#include "Sound.h"
#include "Game.h"

namespace ApplesGame {
	void InitSound(Sound& sound)
	{
		sound.deathSound.setBuffer(sound.deathBuffer);
		sound.eatSound.setBuffer(sound.eatBuffer);
	}
}