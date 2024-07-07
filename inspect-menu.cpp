#include "inspect-menu.h"
#include "ui_inspect-menu.h"


InspectMenu::InspectMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InspectMenu)
{
    ui->setupUi(this);
    this->ui->addressErrorLbl->setVisible(false);
    this->ui->memoryErrorLbl->setVisible(false);

    //

}

InspectMenu::~InspectMenu()
{
    delete ui;
}

void InspectMenu::on_backBtn_clicked()
{
    mainWindow->loadMemoryStalker();
}
