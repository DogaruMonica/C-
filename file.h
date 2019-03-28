#pragma once

#include <QWidget>
#include "ui_file.h"
#include"QtGuiLap1214.h"
class file : public QWidget
{
	Q_OBJECT
private:
	Ui::file ui;
	Controller &ctrl;
public:
	file(Controller & c, QWidget *parent = Q_NULLPTR);
	~file();
signals:
	void csvButtonSignal();
	void htmlButtonSignal();
	public slots:
	void connectSignalsAndSlots();
	void csvButtonHandler();
	void htmlButtonHandler();

};
