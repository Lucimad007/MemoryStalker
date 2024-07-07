#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setup-menu.h"
#include "memory-stalker.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    originalWidget = this->centralWidget();
}

void MainWindow::loadSetupMenu()
{
    SetupMenu *setupMenu = new SetupMenu();
    this->centralWidget()->deleteLater();
    this->setCentralWidget(setupMenu);
}

void MainWindow::loadMainWindow()
{
    MainWindow *window = new MainWindow();
    this->centralWidget()->deleteLater();
    this->setCentralWidget(window);
}


void MainWindow::loadMemoryStalker()
{
    MemoryStalker *app = new MemoryStalker();
    this->centralWidget()->deleteLater();
    this->setCentralWidget(app);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startBtn_clicked()
{
    loadSetupMenu();
}

void MainWindow::on_tutorialBtn_clicked()
{

}

void MainWindow::on_creditsBtn_clicked()
{

}
