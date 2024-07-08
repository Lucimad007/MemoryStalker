#ifndef INSPECTMENU_H
#define INSPECTMENU_H

#include <QWidget>
#include "mainwindow.h"

extern MainWindow *mainWindow;

namespace Ui {
class InspectMenu;
}

class InspectMenu : public QWidget
{
    Q_OBJECT

public:
    explicit InspectMenu(QWidget *parent = nullptr);
    ~InspectMenu();

private slots:
    void on_backBtn_clicked();

    void on_showBtn_clicked();

private:
    Ui::InspectMenu *ui;
};

#endif // INSPECTMENU_H
