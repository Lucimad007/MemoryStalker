#include "memory-stalker.h"
#include "ui_memory-stalker.h"

MemoryStalker::MemoryStalker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoryStalker)
{
    ui->setupUi(this);
    this->ui->invalidAddressLbl->setVisible(false);
    this->ui->rangeCB->setVisible(false);
    this->ui->rangeLbl->setVisible(false);

    //

}

MemoryStalker::~MemoryStalker()
{
    delete ui;
}

void MemoryStalker::on_backBtn_clicked()
{
    mainWindow->loadSetupMenu();
}

void MemoryStalker::on_accessModeCB_currentIndexChanged(int index)
{
    if(index == 0)
    {
        this->ui->rangeCB->setVisible(false);
        this->ui->rangeLbl->setVisible(false);
    } else if(index == 1)
    {
        this->ui->rangeCB->setVisible(true);
        this->ui->rangeLbl->setVisible(true);
    }
}
