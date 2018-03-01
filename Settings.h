#pragma once
class Settings
{
public:
	Settings();
	~Settings();
	bool stillPlay();
	bool endGame();
	void setEndGame(bool b);
	int getPlayTime();
	void setSpeed(double speed_percentage);
	void setArrowCount(int arrowCount);
	void setNextArrow(double arrow_percentage);
	void setDoubleProb(double probability);

private:
	double speed_scale;
	double multi_prob;
	double next_percentage;
	int play_time;
	short arrow_count;
	bool is_end;
	bool is_playing;
};

