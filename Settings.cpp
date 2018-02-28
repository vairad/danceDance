#include "Settings.h"



Settings::Settings()
{
	is_playing = true;
	is_end = false;
}


Settings::~Settings()
{
}

bool Settings::stillPlay()
{
	return is_playing;
}

bool Settings::endGame()
{
	return is_end;
}

void Settings::setEndGame(bool b)
{
	is_end = b;
}
