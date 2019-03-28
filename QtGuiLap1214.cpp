#include "QtGuiLap1214.h"
#include"ui_QtGuiLap1214.h"
#include<string>
QtGuiLap1214::QtGuiLap1214(Controller & c,QWidget *parent)
	:ctrl{ c }, QMainWindow(parent)
{
	
	ui.setupUi(this);
	this->connectSignalsAndSlots();
	//this->populateEventList();
}
void QtGuiLap1214::init()
{
	this->connectSignalsAndSlots();
}

int QtGuiLap1214::getSelectedIndex()
{
	if (this->ui.eventsList->count() == 0)
		return -1;


	QModelIndexList index = this->ui.eventsList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->ui.titleEdit->clear();
		this->ui.descriptionEdit->clear();
		this->ui.timeEdit->clear();
		this->ui.durationEdit->clear();
		this->ui.peopleEdit->clear();
		this->ui.linkEdit->clear();

		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void QtGuiLap1214::connectSignalsAndSlots()
{

	this->ui.chooseBox->addItem("Detalied");
	this->ui.chooseBox->addItem("Short");
	QObject::connect(this->ui.chooseBox, SIGNAL(currentTextChanged(QString)),this, SLOT(combo(QString)));

	//QObject::connect(this, &QtGuiLap1214::eventsUpdatedSignal, this, &QtGuiLap1214::populateEventList);
	QObject::connect(this->ui.eventsList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged(); });
	QObject::connect(this->ui.addButton, SIGNAL(clicked()), this, SLOT(addEventsButtonHandler()));
	QObject::connect(this->ui.deleteButton, SIGNAL(clicked()), this, SLOT(deleteEventButtonHandler()));
	QObject::connect(this->ui.updateButton, SIGNAL(clicked()), this, SLOT(updateEventButtonHandler()));

	
	
}

void QtGuiLap1214::populateEventList()
{
	if (this->ui.eventsList->count() > 0)
		this->ui.eventsList->clear();

	for (auto g : this->ctrl.getRepo())
	{
		QString itemInList;
		std::string t, p, q;
		if (g.getTime().getMinutes() < 10)
			 t = '0' + std::to_string(g.getTime().getMinutes());
		else 
			 t =std::to_string(g.getTime().getMinutes());

		if (g.getDate().getDay()<10)
			 p = '0' + std::to_string(g.getDate().getDay());
		else 
			 p = std::to_string(g.getDate().getDay());
		if (g.getDate().getMonth()<10)

			 q = '0' + std::to_string(g.getDate().getMonth());
		else
			q =std::to_string(g.getDate().getMonth());

		itemInList = QString::fromStdString(g.getTitle() + '-' + g.getDescription() + '-' + std::to_string(g.getTime().getHour()) + ':' + t + '-' + p + '.' + q + '.' + std::to_string(g.getDate().getYear()) + '-' + std::to_string(g.getPeopleGoing()) + '-' + g.getLink());
		QFont f{ "Verdana", 12 };
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		item->setFont(f);
		this->ui.eventsList->addItem(item);
	}


	if (this->ctrl.getRepo().size() > 0)
		this->ui.eventsList->setCurrentRow(0);
}

void QtGuiLap1214::listItemChanged()
{
	int idx = this->getSelectedIndex();
	if (idx == -1)
		return;


	if (idx >= this->ctrl.getRepo().size())
		return;
	Events g = this->ctrl.getRepo()[idx];
	std::string t, p, q;
	this->ui.titleEdit->setText(QString::fromStdString(g.getTitle()));
	this->ui.descriptionEdit->setText(QString::fromStdString(g.getDescription()));

	if(g.getTime().getMinutes()<10)
		t = '0' + std::to_string(g.getTime().getMinutes());
	
	else 
		t = std::to_string(g.getTime().getMinutes());

	this->ui.timeEdit->setText(QString::fromStdString(std::to_string(g.getTime().getHour()) + ':' + t));

	if (g.getDate().getDay() < 10)
		p = '0' + std::to_string(g.getDate().getDay());
	else
		p = std::to_string(g.getDate().getDay());

	if(g.getDate().getMonth()<10)
		q = '0' + std::to_string(g.getDate().getMonth());
		
	else 
		q = std::to_string(g.getDate().getMonth());
	this->ui.durationEdit->setText(QString::fromStdString(p + '.' + q + '.' + std::to_string(g.getDate().getYear())));
	
	this->ui.peopleEdit->setText(QString::fromStdString(std::to_string(g.getPeopleGoing())));
	this->ui.linkEdit->setText(QString::fromStdString(g.getLink()));
}

void QtGuiLap1214::deleteEventButtonHandler()
{
	QString title = this->ui.titleEdit->text();
	QString link = this->ui.linkEdit->text();

	this->ctrl.deleteAnEventCtrl(link.toStdString(), title.toStdString());

	emit eventsUpdatedSignal();
}

void QtGuiLap1214::updateEventButtonHandler()
{
	QString title = this->ui.titleEdit->text();
	QString description = this->ui.descriptionEdit->text();
	QString time = this->ui.timeEdit->text();
	QString date = this->ui.durationEdit->text();
	QString people = this->ui.peopleEdit->text();
	QString link = this->ui.linkEdit->text();
	std::string s = date.toStdString().substr(3, 2);
	std::string t = date.toStdString().substr(7, 2);
	std::string p = date.toStdString().substr(6, 4);
	this->ctrl.updateCtrl(title.toStdString(), description.toStdString(), stoi(date.toStdString().substr(7, 2)), stoi(date.toStdString().substr(3, 2)), stoi(date.toStdString().substr(6, 4)), std::stoi(time.toStdString().substr(0, 2)), std::stoi(time.toStdString().substr(3, 2)), std::stod(people.toStdString()), link.toStdString());
	emit eventsUpdatedSignal();
}

void QtGuiLap1214::showDetalied()
{
	if (this->ui.eventsList->count() > 0)
		this->ui.eventsList->clear();

	for (auto g : this->ctrl.getRepo())
	{
		QString itemInList = QString::fromStdString(g.getTitle()) ;
		QFont f{ "Verdana", 12 };
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		item->setFont(f);
		this->ui.eventsList->addItem(item);
	}


	if (this->ctrl.getRepo().size() > 0)
		this->ui.eventsList->setCurrentRow(0);

}

void QtGuiLap1214::combo(QString q)
{
		if (q.toStdString() == "Detalied")
		{
			QObject::connect(this, &QtGuiLap1214::eventsUpdatedSignal, this, &QtGuiLap1214::populateEventList);
			emit eventsUpdatedSignal();
		}
		if (q.toStdString() == "Short")
		{
			QObject::connect(this, &QtGuiLap1214::eventsUpdatedSignal, this, &QtGuiLap1214::showDetalied);
			emit eventsUpdatedSignal();
		}

	
}

void QtGuiLap1214::addEventsButtonHandler()
{
	QString title = this->ui.titleEdit->text();
	QString description = this->ui.descriptionEdit->text();
	QString time = this->ui.timeEdit->text();
	QString date = this->ui.durationEdit->text();
	QString people = this->ui.peopleEdit->text();
	QString link = this->ui.linkEdit->text();

	
	this->ctrl.addEventsCtrl(title.toStdString(), description.toStdString(), stoi(date.toStdString().substr(7, 2)) , stoi(date.toStdString().substr(3, 2)), stoi(date.toStdString().substr(6, 4)),std::stoi(time.toStdString().substr(0,2)), std::stoi(time.toStdString().substr(3,2)),std::stod( people.toStdString()), link.toStdString());

	emit eventsUpdatedSignal();
}





