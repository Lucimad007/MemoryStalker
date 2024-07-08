#include "mainwindow.h"

#include <QApplication>
#include "memoryhierarchy.h"

MemoryHierarchy *randMemory = nullptr;
MainWindow *mainWindow = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow = new MainWindow();
    randMemory = new MemoryHierarchy();

    mainWindow->show();
    return a.exec();
}
