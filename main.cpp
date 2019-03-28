#include "QtGuiLap1214.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
#include"CSVEvents.h"
#include"EventsValidator.h"
#include"Menu.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	



	EventsRepository repo{ "file.txt" };
	FileEventslist* evl = new CSVEventslist{ "CSVEvents.csv" };
	EventsValidator ev{};
	Controller ctrl{ repo,evl,ev };
	Menu w{ ctrl };
	w.show();
	return a.exec();
}
