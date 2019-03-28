#pragma once

#include <QWidget>
#include "ui_Menu.h"
#include"Controller.h"
#include"QtGuiLap1214.h"
class Menu : public QWidget
{
	Q_OBJECT
private:
	Ui::Menu ui;
	Controller& ctrl;
public:

	Menu(Controller & c,QWidget *parent = Q_NULLPTR);
	~Menu();
	void connectSignalsAndSlots();
signals:
	void eventsUpdatedSignal();
	void administratorButtonSignal();
	void userButtonSignal();
	public slots:
	void administratorButtonHandler();
	void userButtonHandler();
};
