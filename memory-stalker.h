#ifndef MEMORYSTALKER_H
#define MEMORYSTALKER_H

#include <QWidget>
#include "mainwindow.h"

extern MainWindow *mainWindow;

namespace Ui {
class MemoryStalker;
}

class MemoryStalker : public QWidget
{
    Q_OBJECT

public:
    explicit MemoryStalker(QWidget *parent = nullptr);
    ~MemoryStalker();

private slots:
    void on_backBtn_clicked();

    void on_accessModeCB_currentIndexChanged(int index);

    void on_inspectBtn_clicked();

private:
    Ui::MemoryStalker *ui;
};

#endif // MEMORYSTALKER_H
