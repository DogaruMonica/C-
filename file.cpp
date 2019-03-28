#include "file.h"
#include"User.h"
file::file(Controller & c,QWidget *parent)
	:ctrl{ c }, QWidget(parent)
{
	ui.setupUi(this);
	this->connectSignalsAndSlots();
}

file::~file()
{
}
void file::connectSignalsAndSlots()
{
	QObject::connect(this->ui.csvButton, SIGNAL(clicked()), this, SLOT(csvButtonHandler()));
	QObject::connect(this->ui.htmlButton, SIGNAL(clicked()), this, SLOT(htmlButtonHandler()));
}
void file::htmlButtonHandler()
{
	this->ctrl.setEventsFile(2);
	User * f = new User{ ctrl };
	f->show();
	emit csvButtonSignal();
}
void file::csvButtonHandler()
{
	this->ctrl.setEventsFile(1);
	User* f = new User{ ctrl };
	f->show();
	emit htmlButtonSignal();
}