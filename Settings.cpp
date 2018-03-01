#include "settings.h"

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

int Settings::getPlayTime()
{
	return play_time;
}

void Settings::setSpeed(double speed_percentage)
{
	speed_scale = speed_percentage;
}

void Settings::setArrowCount(int arrowCount)
{
	arrow_count = arrowCount;
}

void Settings::setNextArrow(double arrow_percentage)
{
	next_percentage = arrow_percentage;
}

void Settings::setDoubleProb(double probability)
{
	multi_prob = probability;
}

void Settings::setEndGame(bool b)
{
	is_end = b;
}
