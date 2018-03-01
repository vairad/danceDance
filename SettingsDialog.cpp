#include <QMessageBox>

#include "ui_settings.h"
#include "settingsdialog.h"
#include "playcolumn.h"

SettingsDialog::SettingsDialog(Settings * settings_ref, QWidget * parent)
	: QDialog(parent)
	, ui(new Ui::SettingsDlg)
	, settings(settings_ref)
{
	ui->setupUi(this);
	this->setWindowTitle("DanceDance Settings");

	QPushButton *startButton = ui->startButton;
	connect(startButton, SIGNAL(clicked()), this, SLOT(startGame()));

	QPushButton *resetButton = ui->resetButton;
	connect(resetButton, SIGNAL(clicked()), this, SLOT(resetProps()));

	speedSlider = ui->speedSlider;
    arrowCountSlider = ui->arrowCountSlider;
	nextArrowSlider = ui->nextArrowSlider;
	probabilitySlider = ui->probOfTwoSlider;

	connect(speedSlider, SIGNAL(valueChanged(int)), this, SLOT(updateSettings()));
	connect(arrowCountSlider, SIGNAL(valueChanged(int)), this, SLOT(updateSettings()));
	connect(nextArrowSlider, SIGNAL(valueChanged(int)), this, SLOT(updateSettings()));
	connect(probabilitySlider, SIGNAL(valueChanged(int)), this, SLOT(updateSettings()));

	updateSettings();
}

SettingsDialog::~SettingsDialog()
{
}

void SettingsDialog::startGame()
{
		if(playgame)
		{
			playgame->close();
			delete playgame;
		}
		playgame = new PlayColumn(settings);
		playgame->show();
}

void SettingsDialog::resetProps()
{
	QMessageBox::warning(this, "DanceDance Simulator", "Nefunguje Blbý co?", QMessageBox::Yes);
}


void SettingsDialog::updateSettings()
{
	const auto speed = speedSlider->value() / 100.0;
	settings->setSpeed(speed);
	ui->speedSliderVal->setText(QString::number(speed));

	const auto arrow = arrowCountSlider->value();
	settings->setArrowCount(arrow);
	ui->arrowCountVal->setText(QString::number(arrow));

	const auto nextArrow = nextArrowSlider->value() / 100.0;
	settings->setNextArrow(nextArrow);
	ui->nextArrowVal->setText(QString::number(nextArrow));

	const auto prob = probabilitySlider->value() / 100.0;
	settings->setDoubleProb(prob);
	ui->probOfTwoVal->setText(QString::number(prob));
}

void SettingsDialog::closeEvent(QCloseEvent *event) {
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "DanceDance Simulator", "Are you sure to quit?", QMessageBox::Yes | QMessageBox::No);

	if (reply == QMessageBox::Yes) {
		QApplication::closeAllWindows();
		event->accept();
		this->close();
		playgame->close();
		delete playgame;
		return;
	}
	event->ignore();
}