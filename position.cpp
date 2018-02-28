#include "position.h"


int Position::min_progress = 1000;

Position::Position(const Column index) :
	position(index),
	progress(0)
{
}

void Position::move()
{
	progress++;
	progress++;
	if(progress < min_progress)
	{
		min_progress = min_progress;
	}
}

Column Position::getColumn() const
{
	return progress >=1000 ? INVALID : position;
}

double Position::getProgress() const
{
	return progress / 1000.0 ;
}

bool Position::create_new_position()
{
	return (min_progress > 20);
}
