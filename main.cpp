#include <QtGui>

#include "playcolumn.h"
#include "Settings.h"
#include "SettingsDialog.h"
#include "mainwindow.h"

void runGame(Settings * settings)
{
	while(settings->stillPlay())
	{
		PlayColumn clock(settings);
		clock.show();
	}
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

	Settings settings;

	SettingsDialog settings_dialog(&settings);
	
	while(!settings.endGame())
	{
		settings_dialog.exec();
	}

	//return app.exec();
    return 0;
}
