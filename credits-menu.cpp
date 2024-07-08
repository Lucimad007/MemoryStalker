#include "credits-menu.h"
#include "ui_credits-menu.h"

CreditsMenu::CreditsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditsMenu)
{
    ui->setupUi(this);
}

CreditsMenu::~CreditsMenu()
{
    delete ui;
}

void CreditsMenu::on_backBtn_clicked()
{
    mainWindow->loadMainWindow();
}
