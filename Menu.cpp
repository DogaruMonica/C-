#include "Menu.h"
#include"file.h"
Menu::Menu(Controller &c,QWidget *parent)
	: ctrl{ c }, QWidget(parent)
{
	ui.setupUi(this);
	this->connectSignalsAndSlots();
}

Menu::~Menu()
{
}
void Menu::connectSignalsAndSlots()
{
	QObject::connect(this->ui.administratorButton, SIGNAL(clicked()), this, SLOT(administratorButtonHandler()));
	QObject::connect(this->ui.userButton, SIGNAL(clicked()), this, SLOT(userButtonHandler()));
}
void Menu::administratorButtonHandler()
{
	QtGuiLap1214*  n = new QtGuiLap1214{ ctrl };
	n->show();
	emit eventsUpdatedSignal();
}
void Menu::userButtonHandler()
{
	file*  p = new file{ ctrl };
	p->show();
	emit eventsUpdatedSignal();

}
