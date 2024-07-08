#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void loadSetupMenu();
    void loadMainWindow();
    void loadMemoryStalker();
    void loadInspectMenu();
    void loadCreditsMenu();

    ~MainWindow();

private slots:
    void on_startBtn_clicked();

    void on_tutorialBtn_clicked();

    void on_creditsBtn_clicked();

private:
    Ui::MainWindow *ui;
    QWidget *originalWidget;
};
#endif // MAINWINDOW_H
