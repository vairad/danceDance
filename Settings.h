#pragma once
class Settings
{
public:
	Settings();
	~Settings();
	bool stillPlay();
	bool endGame();
	void setEndGame(bool b);
private:
	bool is_playing;
	bool is_end;
};

