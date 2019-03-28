#include "User.h"

User::User(Controller & c,QWidget *parent)
	:ctrl{ c }, QWidget(parent)
{
	ui.setupUi(this);

	this->connectSignalsAndSlots();

	this->i = 0;
}

User::~User()
{
}
void User::connectSignalsAndSlots()
{
	QObject::connect(this->ui.saveButton,  SIGNAL(clicked()), this,SLOT(saveButtonHandler()));
	QObject::connect(this->ui.fileButton,  SIGNAL(clicked()), this,SLOT(openButtonHandler()));
	QObject::connect(this->ui.filterButton,SIGNAL(clicked()), this,SLOT(filterButtonHnandler()));
	QObject::connect(this->ui.nextButton,  SIGNAL(clicked()), this,SLOT(nextButtonHandler()));
	QObject::connect(this,&User::eventsUpdatedSignal,this,&User::populateEventsList);
	QObject::connect(this->ui.addButton,   SIGNAL(clicked()), this,SLOT(addButtonHandler()));
	QObject::connect(this->ui.deleteButton,SIGNAL(clicked()), this,SLOT(deleteButtonHandler()));

}
void User::populateEventsList()
{
	if (this->ui.list->count() > 0)
		this->ui.list->clear();
	for (auto g : this->ctrl.getEventsList())
	{
		QString itemInList;
		std::string t, p, q;
		if (g.getTime().getMinutes() < 10)
			t = '0' + std::to_string(g.getTime().getMinutes());
		else
			t = std::to_string(g.getTime().getMinutes());

		if (g.getDate().getDay() < 10)
			p = '0' + std::to_string(g.getDate().getDay());
		else
			p = std::to_string(g.getDate().getDay());
		if (g.getDate().getMonth() < 10)

			q = '0' + std::to_string(g.getDate().getMonth());
		else
			q = std::to_string(g.getDate().getMonth());

		itemInList = QString::fromStdString(g.getTitle() + '-' + g.getDescription() + '-' + std::to_string(g.getTime().getHour()) + ':' + t + '-' + p + '.' + q + '.' + std::to_string(g.getDate().getYear()) + '-' + std::to_string(g.getPeopleGoing()) + '-' + g.getLink());
		QListWidgetItem* l = new QListWidgetItem{ itemInList };

		QFont f = { "verdana",12 };
		l->setFont(f);
		this->ui.list->addItem( l );
	}
	if (this->ctrl.getEventsList().size() > 0)
		this->ui.list->setCurrentRow(0);
}
int User::getSelectedIndex()
{
	if (this->ui.events->count() == 0)
		return -1;
	QModelIndexList index = this->ui.events->selectionModel()->selectedIndexes();
	int idx = index.at(0).row();
	return idx;
}

void User::filterButtonHnandler()
{
	int m;
	if (this->ui.events->count() > 0)
		return;
	QString month = this->ui.monthEdit->text();
	if (month.toStdString().length() == 0)
		 m = -1;
	else m = std::stoi(month.toStdString());
	for (auto g : this->ctrl.seeEventsByMonthCtrl(m))
	{
		QString itemInList;
		std::string t, p, q;
		if (g.getTime().getMinutes() < 10)
			t = '0' + std::to_string(g.getTime().getMinutes());
		else
			t = std::to_string(g.getTime().getMinutes());

		if (g.getDate().getDay() < 10)
			p = '0' + std::to_string(g.getDate().getDay());
		else
			p = std::to_string(g.getDate().getDay());
		if (g.getDate().getMonth() < 10)

			q = '0' + std::to_string(g.getDate().getMonth());
		else
			q = std::to_string(g.getDate().getMonth());
		itemInList = QString::fromStdString(g.getTitle() + ',' + g.getDescription() + ',' + std::to_string(g.getTime().getHour()) + ':' + t + ',' + p + '.' + q + '.' + std::to_string(g.getDate().getYear()) + ',' + std::to_string(g.getPeopleGoing()) + ',' + g.getLink());
		QListWidgetItem * list = new QListWidgetItem{ itemInList };
		QFont f{ "Verdana",12 };
		list->setFont(f);
		this->ui.events->addItem(list);
	}
	this->ui.events->setCurrentRow(0);
	emit eventsUpdatedSignal();
}
void User::addButtonHandler()
{
	int m, idx = this->nextButtonHandler();

	QString month = this->ui.monthEdit->text();
	if (month.toStdString().length() == 0)
		m = -1;
	else m = std::stoi(month.toStdString());

	Events e = this->ctrl.seeEventsByMonthCtrl(m)[idx];
	this->ctrl.addELCtrl(e);
	this->populateEventsList();
	emit eventsUpdatedSignal();
}
int User::nextButtonHandler()
{
	int m;
	
	QString month = this->ui.monthEdit->text();
	if (month.toStdString().length() == 0)
		m = -1;
	else m = std::stoi(month.toStdString());

	
	if (this->i+1 == this->ctrl.seeEventsByMonthCtrl(m).size())
	{
		this->i = 0;
		this->ui.events->setCurrentRow(this->i);
	}
	else {
		this->i++;
		this->ui.events->setCurrentRow(this->i);
	}
	return this->i;
}
int User::getSelectedIndexEL()
{
	if (this->ui.list->count() == 0)
		return -1;
	QModelIndexList index = this->ui.list->selectionModel()->selectedIndexes();
	int idx = index.at(0).row();
	return idx;
}
void User::deleteButtonHandler()
{

	int  idx = this->getSelectedIndexEL();
	if (idx > this->ctrl.getEventsList().size())
		return;
	else {
		Events e = this->ctrl.getEventsList()[idx];
		this->ctrl.deleteElCtrl(e);
		this->populateEventsList();
	}
}
void User::openButtonHandler()
{
	this->ctrl.Display();
	emit eventsUpdatedSignal();
}
void User::saveButtonHandler()
{
	this->ctrl.SaveFileList();
	emit eventsUpdatedSignal();
}