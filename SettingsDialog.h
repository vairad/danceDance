#pragma once

#include <QDialog>
#include "ui_settings.h"
#include "Settings.h"

class SettingsDialog : public QDialog, public Ui::SettingsDlg
{
	Q_OBJECT
public:
	SettingsDialog(Settings *settings_ref, QWidget * parent = nullptr);
	~SettingsDialog();

public slots:
	void exitProgram();
	void startGame();
	void resetProps();
private:
	Settings * settings;
	Ui::SettingsDlg *ui;
};

 