#pragma once

#include <QDialog>
#include "ui_settings.h"
#include "settings.h"
#include "playcolumn.h"

class SettingsDialog : public QDialog, public Ui::SettingsDlg
{
	Q_OBJECT
public:
	SettingsDialog(Settings *settings_ref, QWidget * parent = nullptr);
	~SettingsDialog();
	void closeEvent(QCloseEvent * event) override;

public slots:
	void startGame();
	void resetProps();
	void updateSettings();

private:
	Settings * settings;
	Ui::SettingsDlg *ui;

	QSlider * speedSlider;
	QSlider * arrowCountSlider;
	QSlider * nextArrowSlider;
	QSlider * probabilitySlider;

	PlayColumn * playgame = nullptr;
};

 