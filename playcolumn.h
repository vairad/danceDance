#ifndef PLAYCOLUMN_H
#define PLAYCOLUMN_H

#include <QtGui>

#include "settings.h"
#include "rasterwindow.h"
#include "position.h"

class PlayColumn : public RasterWindow
{
public:
	void initialisePolygons();

    PlayColumn(Settings * set);
	
	QPolygon Arrow[4];

	const QColor waitingColoure = QColor(127, 0, 127);
	const QColor nowColoure = QColor(255, 255, 20);
	const QColor doneColoure = QColor(127, 127, 127);
	const QColor lineColoure = QColor(60, 60, 60);
	const QColor targetColoure = QColor(255, 60, 60);

	std::mutex arrows_lock;
	
protected:
    void timerEvent(QTimerEvent *) override;
	void renderHeader(QPainter* p);
	void setCenters();
	void render(QPainter *p) override;
private:
    int m_timerId;
	size_t counter;

	std::list<Position *> arrows;

	Settings * settings;

	Column getRandomColumn();

	int m_columnWidth;;
	int m_columnCenter[4];

};

#endif // PLAYCOLUMN_H
