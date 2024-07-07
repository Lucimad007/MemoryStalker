#ifndef SETUPMENU_H
#define SETUPMENU_H

#include <QWidget>
#include "mainwindow.h"
#include "memory-stalker.h"

extern MainWindow *mainWindow;

namespace Ui {
class SetupMenu;
}

class SetupMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SetupMenu(QWidget *parent = nullptr);
    ~SetupMenu();

private slots:
    void on_backBtn_clicked();

    void on_cacheLevelsCB_currentIndexChanged(int index);

    void on_nextBtn_clicked();

private:
    Ui::SetupMenu *ui;
};

#endif // SETUPMENU_H
