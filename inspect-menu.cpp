#include "inspect-menu.h"
#include "ui_inspect-menu.h"
#include "memoryhierarchy.h"

extern MemoryHierarchy *randMemory;


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

void InspectMenu::on_showBtn_clicked()
{
    ui->addressErrorLbl->setVisible(false);
    ui->memoryErrorLbl->setVisible(false);
    QString str = ui->addressLineEdit->text();
    ui->addressLineEdit->setText("");

    bool ok;  // This will be set to true if the conversion succeeds
    int address = str.toInt(&ok);

    if (ok) {

        switch (ui->memoryCB->currentIndex()) {
        case 0:
            if(address < 0 || address > randMemory->getL1().getSize())
            {
                ui->addressErrorLbl->setVisible(true);
                return;
            } else
            {

            }

            break;
        case 1:
            if(randMemory->getLevel() == 1)
            {
                ui->memoryErrorLbl->setVisible(true);
                return;
            }

            if(address < 0 || address > randMemory->getL2().getSize())
            {
                ui->addressErrorLbl->setVisible(true);
                return;
            } else
            {

            }

            break;
        case 2:
            if(randMemory->getLevel() == 2)
            {
                ui->memoryErrorLbl->setVisible(true);
                return;
            }

            if(address < 0 || address > randMemory->getL3().getSize())
            {
                ui->addressErrorLbl->setVisible(true);
                return;
            } else
            {

            }

            break;
        case 3:

            if(address < 0 || address > randMemory->getRAM().getSize())
            {
                ui->addressErrorLbl->setVisible(true);
                return;
            } else
            {

            }

            break;

        }

    } else {
        ui->addressErrorLbl->setVisible(true);
        return;
    }

}
