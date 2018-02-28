#include "playcolumn.h"

#include <stdlib.h>
#include <QPolygon>


void PlayColumn::initialisePolygons()
{
	Arrow[BOTTOM] << QPoint(00, 50) << QPoint(50, 00) << QPoint(20, 00) << QPoint(20, -50) << QPoint(-20, -50) << QPoint(-20, 00) << QPoint(-50, 00);
	Arrow[TOP] << QPoint(00, -50) << QPoint(-50, 00) << QPoint(-20, 00) << QPoint(-20, 50) << QPoint(20, 50) << QPoint(20, 00) << QPoint(50, 00);
	Arrow[RIGHT] << QPoint(50, 00) << QPoint(00, -50) << QPoint(00, -20) << QPoint(-50, -20) << QPoint(-50, 20) << QPoint(00, 20) << QPoint(00, 50);
	Arrow[LEFT] << QPoint(-50, 00) << QPoint(00, 50) << QPoint(00, 20) << QPoint(50, 20) << QPoint(50, -20) << QPoint(00, -20) << QPoint(00, -50);
}

PlayColumn::PlayColumn(Settings * set)
	:settings(set)
{
    setTitle("DanceDance Simulator");
    resize(400, 400);

	pos = new Position(TOP);

	initialisePolygons();

    m_timerId = startTimer(1);
}

void PlayColumn::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timerId)
    {
		pos->move();
		renderLater();
    }
       
}


void PlayColumn::renderHeader(QPainter *p)
{
	int iHeight = height();


	const QRect rect(0, iHeight * 0.1 , width() , iHeight * 0.3);
	p->setBrush(targetColoure);
	p->drawRect(rect);

	QPainterPath path;
	path.moveTo(m_columnWidth, iHeight);
	path.lineTo(m_columnWidth, 0);
	
	path.moveTo(m_columnWidth * 2, iHeight);
	path.lineTo(m_columnWidth * 2, 0);

	path.moveTo(m_columnWidth * 3, iHeight);
	path.lineTo(m_columnWidth * 3, 0);

	p->setPen(waitingColoure);
	p->drawPath(path);

}

void PlayColumn::setCenters()
{
	m_columnWidth = width() / 4;
	m_columnCenter[LEFT] = m_columnWidth / 2;
	m_columnCenter[TOP] = m_columnCenter[LEFT] + m_columnWidth;
	m_columnCenter[BOTTOM] = m_columnCenter[TOP] + m_columnWidth;
	m_columnCenter[RIGHT] = m_columnCenter[BOTTOM] + m_columnWidth;
}

void PlayColumn::render(QPainter *p)
{
    p->setRenderHint(QPainter::Antialiasing);

	setCenters();
	renderHeader(p);


    p->translate(width() / 2, height() / 2);

    int side = qMin(width(), height());
	double scale = side / 500.0;

    p->setPen(Qt::NoPen);


    p->save();
	p->resetTransform();
	const int col = pos->getColumn();
	const double inv_prog = 1 - pos->getProgress();
	p->setBrush(waitingColoure);
	if(pos->getProgress() >= 0.75)
	{
		p->setBrush(nowColoure);
	}
	if (pos->getProgress() >= 0.9)
	{
		p->setBrush(doneColoure);
	}

	if (col == INVALID)
	{
		const Column index = getRandomColumn();
		pos = new Position(index);
		return;
	}

	p->translate(m_columnCenter[col], height() * inv_prog);
	p->drawConvexPolygon(Arrow[col]);
    p->restore();
}

Column PlayColumn::getRandomColumn()
{
	int irand = rand() % 4;
	switch (irand)
	{
	case 0:
		return LEFT;
	case 1:
		return TOP;
	case 2: 
		return RIGHT;
	case 3:
		return BOTTOM;
	}
	return INVALID;
}


