#pragma once

#include <QWidget>
#include "ui_User.h"
#include"Controller.h"

class User : public QWidget
{
	Q_OBJECT
private:
	Ui::User ui;
	Controller & ctrl;
	void connectSignalsAndSlots();
	int getSelectedIndex();
	int i;
	int getSelectedIndexEL();
	void populateEventsList();
public:
	User(Controller & c, QWidget *parent = Q_NULLPTR);
	~User();

signals:
	void eventsUpdatedSignal();
	void addUpdatedSignal();
	
	void deleteUpdateSignal();
	void nextUpdatedSignal();
	void filterUpdatedSignal();
	public slots:

	void addButtonHandler();
	void deleteButtonHandler();
	int nextButtonHandler();
	void filterButtonHnandler();
	void openButtonHandler();
	void saveButtonHandler();

};
