#pragma once
#include "Settings.h"

enum Column
{
	BOTTOM = 0,
	LEFT,
	TOP,
	RIGHT,
	INVALID
};


class Position
{
private:
	int progress;
	const Column position;
	static int min_progress;
public:
	Position(Column index);
	
	void move();
	Column getColumn() const;
	double getProgress() const;

	static double getMinimum();
	static void resetMinimum();

	static bool create_new_position();
};