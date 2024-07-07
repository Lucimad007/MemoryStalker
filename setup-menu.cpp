#include "setup-menu.h"
#include "ui_setup-menu.h"

SetupMenu::SetupMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetupMenu)
{
    ui->setupUi(this);
}

SetupMenu::~SetupMenu()
{
    delete ui;
}

void SetupMenu::on_backBtn_clicked()
{
    mainWindow->loadMainWindow();
}

void SetupMenu::on_cacheLevelsCB_currentIndexChanged(int index)
{
    if(index == 0)
    {
        this->ui->L2SizeCB->setVisible(false);
        this->ui->L2SizeLbl->setVisible(false);
        this->ui->L3SizeCB->setVisible(false);
        this->ui->L3SizeLbl->setVisible(false);
    } else if(index == 1)
    {
        this->ui->L2SizeCB->setVisible(true);
        this->ui->L2SizeLbl->setVisible(true);
        this->ui->L3SizeCB->setVisible(false);
        this->ui->L3SizeLbl->setVisible(false);
    } else if(index == 2)
    {
        this->ui->L2SizeCB->setVisible(true);
        this->ui->L2SizeLbl->setVisible(true);
        this->ui->L3SizeCB->setVisible(true);
        this->ui->L3SizeLbl->setVisible(true);
    }
}

void SetupMenu::on_nextBtn_clicked()
{

}
