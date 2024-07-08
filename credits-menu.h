#ifndef CREDITSMENU_H
#define CREDITSMENU_H

#include <QWidget>
#include "mainwindow.h"

extern MainWindow *mainWindow;

namespace Ui {
class CreditsMenu;
}

class CreditsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit CreditsMenu(QWidget *parent = nullptr);
    ~CreditsMenu();

private slots:
    void on_backBtn_clicked();

private:
    Ui::CreditsMenu *ui;
};

#endif // CREDITSMENU_H
