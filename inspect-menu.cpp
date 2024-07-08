#include "inspect-menu.h"
#include "ui_inspect-menu.h"
#include "memoryhierarchy.h"
#include "addresscalculator.h"

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

    int index, tag, firstBlock, valid;

    bool ok;  // This will be set to true if the conversion succeeds
    int address = str.toInt(&ok);
    AddressCalculator calc(randMemory->getL1().getBlockSize());     //all of them have the same block size

    if (ok) {

        switch (ui->memoryCB->currentIndex()) {
        case 0:
            if(address < 0 || address >= randMemory->getL1().getSize())
            {
                ui->addressErrorLbl->setVisible(true);
                return;
            } else
            {
                index = calc.index(address, L1);
                tag = randMemory->getL1().tag(index);
                valid = randMemory->getL1().valid(index);
                firstBlock = randMemory->getL1().value(index, calc.offset(address, L1));
            }

            break;
        case 1:
            if(randMemory->getLevel() == 1)
            {
                ui->memoryErrorLbl->setVisible(true);
                return;
            }

            if(address < 0 || address >= randMemory->getL2().getSize())
            {
                ui->addressErrorLbl->setVisible(true);
                return;
            } else
            {
                index = calc.index(address, L2);
                tag = randMemory->getL2().tag(index);
                valid = randMemory->getL2().valid(index);
                firstBlock = randMemory->getL2().value(index, calc.offset(address, L2));
            }

            break;
        case 2:
            if(randMemory->getLevel() == 2)
            {
                ui->memoryErrorLbl->setVisible(true);
                return;
            }

            if(address < 0 || address >= randMemory->getL3().getSize())
            {
                ui->addressErrorLbl->setVisible(true);
                return;
            } else
            {
                index = calc.index(address, L3);
                tag = randMemory->getL3().tag(index);
                valid = randMemory->getL3().valid(index);
                firstBlock = randMemory->getL3().value(index, calc.offset(address, L3));
            }

            break;
        case 3:

            if(address < 0 || address >= randMemory->getRAM().getSize())
            {
                ui->addressErrorLbl->setVisible(true);
                return;
            } else
            {
                index = calc.index(address, RAM);
                tag = randMemory->getRAM().tag(index);
                valid = randMemory->getRAM().valid(index);
                firstBlock = randMemory->getRAM().value(index, calc.offset(address, RAM));
            }

            break;

        }

    } else {
        ui->addressErrorLbl->setVisible(true);
        return;
    }

    QString str1, str2, str3, str4;
    str1 = QString::number(tag);
    str2 = QString::number(valid);
    str3 = QString::number(index);
    str4 = QString::number(firstBlock);
    ui->tagValueLbl->setText(str1);
    ui->validValueLbl->setText(str2);
    ui->indexValueLbl->setText(str3);
    ui->valueValueLbl->setText(str4);

}
