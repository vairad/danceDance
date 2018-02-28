#include <QMessageBox>

#include "ui_settings.h"
#include "SettingsDialog.h"

SettingsDialog::SettingsDialog(Settings * settings_ref, QWidget * parent)
	: QDialog(parent)
	, ui(new Ui::SettingsDlg)
	, settings(settings_ref)
{
	ui->setupUi(this);
	this->setWindowTitle("DanceDance Settings");


	QPushButton *exitButton = ui->exitButton;
	connect(exitButton, SIGNAL(clicked()), this, SLOT(exitProgram()));

	QPushButton *startButton = ui->startButton;
	connect(exitButton, SIGNAL(clicked()), this, SLOT(startGame()));

	QPushButton *resetButton = ui->resetButton;
	connect(exitButton, SIGNAL(clicked()), this, SLOT(resetProps()));

}

SettingsDialog::~SettingsDialog()
{
}


void SettingsDialog::exitProgram()
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "DanceDance Simulator", "Are you sure to quit?", QMessageBox::Yes | QMessageBox::No);
	
	if (reply == QMessageBox::Yes) {
		settings->setEndGame(true);
		this->close();
	}
}

void SettingsDialog::startGame()
{

}

void SettingsDialog::resetProps()
{

}
