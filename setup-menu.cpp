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
        this->ui->L2SpeedCB->setVisible(false);
        this->ui->L3SizeCB->setVisible(false);
        this->ui->L3SizeLbl->setVisible(false);
        this->ui->L3SpeedCB->setVisible(false);
    } else if(index == 1)
    {
        this->ui->L2SizeCB->setVisible(true);
        this->ui->L2SizeLbl->setVisible(true);
        this->ui->L2SpeedCB->setVisible(true);
        this->ui->L3SizeCB->setVisible(false);
        this->ui->L3SizeLbl->setVisible(false);
        this->ui->L3SpeedCB->setVisible(false);
    } else if(index == 2)
    {
        this->ui->L2SizeCB->setVisible(true);
        this->ui->L2SizeLbl->setVisible(true);
        this->ui->L2SpeedCB->setVisible(true);
        this->ui->L3SizeCB->setVisible(true);
        this->ui->L3SizeLbl->setVisible(true);
        this->ui->L3SpeedCB->setVisible(true);
    }
}

void SetupMenu::on_nextBtn_clicked()
{

    //setting up memory hierarchy

    int blockSize = 1;

    switch (ui->blockSizeCB->currentIndex()) {
    case 0: blockSize = 1; break;
    case 1: blockSize = 2; break;
    case 2: blockSize = 4; break;
    case 3: blockSize = 12; break;
    default: blockSize = 1; break;
    }

    randMemory = new MemoryHierarchy(blockSize);

    randMemory->setLevel(ui->cacheLevelsCB->currentIndex() + 1);

    switch (ui->replacementPolicyCB->currentIndex()) {
    case 0: randMemory->setReplacementPolicy(LRU); break;
    case 1: randMemory->setReplacementPolicy(FIFO); break;
    case 2: randMemory->setReplacementPolicy(RANDOM); break;
    default: randMemory->setReplacementPolicy(RANDOM); break;
    }

    int L1cycle, L1penalty;
    int L2cycle, L2penalty;
    int L3cycle, L3penalty;
    int ramCycle, ramPenalty;
    int hddCycle;
    long long L1size, L2size, L3size, ramSize, hddSize;
    switch (ui->L1SpeedCB->currentIndex()) {
    case 0: L1cycle = 1; break;
    case 1: L1cycle = 2; break;
    case 2: L1cycle = 3; break;
    default: L1cycle = 1; break;
    }

    switch (ui->L1SizeCB->currentIndex()) {
    case 0: L1size = 2; break;
    case 1: L1size = 4; break;
    case 2: L1size = 16; break;
    case 3: L1size = 64; break;
    default: L1size = 2; break;
    }

    switch (ui->L2SpeedCB->currentIndex()) {
    case 0: L2cycle = 12; L1penalty = 12; break;
    case 1: L2cycle = 25; L1penalty = 25; break;
    default: L2cycle = 12; L1penalty = 12; break;
    }

    switch (ui->L2SizeCB->currentIndex()) {
    case 0: L2size = 256; break;
    case 1: L2size = 512; break;
    default: L2size = 256; break;
    }

    switch (ui->L3SpeedCB->currentIndex()) {
    case 0: L3cycle = 30; L2penalty = 30; break;
    case 1: L3cycle = 40; L2penalty = 40; break;
    default: L3cycle = 30; L2penalty = 30; break;
    }

    switch (ui->L3SizeCB->currentIndex()) {
    case 0: L3size = 3072; break;
    case 1: L3size = 4096; break;
    case 2: L3size = 8192; break;
    default: L3size = 3072; break;
    }

    switch (ui->ramSpeedCB->currentIndex()) {
    case 0: ramCycle = 50; L3penalty = 50; break;
    case 1: ramCycle = 70; L3penalty = 70; break;
    case 2: ramCycle = 100; L3penalty = 100; break;
    default: ramCycle = 50; L3penalty = 50; break;
    }

    switch (ui->ramSizeCB->currentIndex()) {
    case 0: ramSize = 4194304; break;
    case 1: ramSize = 8388608; break;
    case 2: ramSize = 16777216; break;
    default: ramSize = 4194304; break;
    }

    switch (ui->hardDriveSpeedCB->currentIndex()) {
    case 0: hddCycle = 3000000; ramPenalty = 3000000; break;
    case 1: hddCycle = 10000000; ramPenalty = 10000000; break;
    case 2: hddCycle = 15000000; ramPenalty = 15000000; break;
    default: hddCycle = 3000000; ramPenalty = 3000000; break;
    }

    switch (ui->hardDriveSizeCB->currentIndex()) {
    case 0: hddSize = 134217728; break;
    case 1: hddSize = 268435456; break;
    default: hddSize = 134217728; break;
    }

    Cache L1(L1cycle, L1penalty, L1size, blockSize);
    Cache L2(L2cycle, L2penalty, L2size, blockSize);
    Cache L3(L3cycle, L3penalty, L3size, blockSize);
    Cache RAM(ramCycle, ramPenalty, ramSize, blockSize);

    randMemory->setL1(L1);
    randMemory->setL2(L2);
    randMemory->setL3(L3);
    randMemory->setRAM(RAM);

    //setting up next ui

    mainWindow->loadMemoryStalker();
}
