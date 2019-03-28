

#pragma once
#include"ui_QtGuiLap1214.h"
#include<string>
#include"Controller.h"
#include <QtWidgets/QMainWindow>
#include "ui_QtGuiLap1214.h"
#include <qwidget.h>
#include "Events.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

class QtGuiLap1214 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiLap1214(Controller & c,QWidget *parent = Q_NULLPTR);
	~QtGuiLap1214() {}
	void init();

private:
	Controller & ctrl;
	Ui::QtGuiLap1214Class ui;

	int getSelectedIndex();
	void connectSignalsAndSlots();
	void populateEventList();
	// When an item in the list is clicked, the text boxes get filled with the item's information
	void listItemChanged();

signals:
	void eventsUpdatedSignal();
	void addEventsSignal();

	public slots:
	//void addEventButtonHandler();
	//void deleteEventButtonHandler();
	void updateEventButtonHandler();
	void showDetalied();
	void combo(QString q);
	void addEventsButtonHandler();
	void deleteEventButtonHandler();

};
