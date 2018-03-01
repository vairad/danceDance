#include  <QtGui>

#include "settings.h"
#include "settingsdialog.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

	Settings settings;

	SettingsDialog settings_dialog(&settings);
	
	settings_dialog.show();

	return app.exec();
}
