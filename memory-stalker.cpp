#include "memory-stalker.h"
#include "ui_memory-stalker.h"
#include <QProcess>
#include <QFile>
#include "memoryhierarchy.h"

extern MemoryHierarchy *randMemory;

MemoryStalker::MemoryStalker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoryStalker)
{
    ui->setupUi(this);
    this->ui->invalidAddressLbl->setVisible(false);
    this->ui->rangeCB->setVisible(false);
    this->ui->rangeLbl->setVisible(false);

    //

}

MemoryStalker::~MemoryStalker()
{
    delete ui;
}

void MemoryStalker::on_backBtn_clicked()
{
    mainWindow->loadSetupMenu();
}

void MemoryStalker::on_accessModeCB_currentIndexChanged(int index)
{
    if(index == 0)
    {
        this->ui->rangeCB->setVisible(false);
        this->ui->rangeLbl->setVisible(false);
    } else if(index == 1)
    {
        this->ui->rangeCB->setVisible(true);
        this->ui->rangeLbl->setVisible(true);
    }
}

void MemoryStalker::on_inspectBtn_clicked()
{
    mainWindow->loadInspectMenu();
}

void MemoryStalker::on_analysisBtn_clicked()
{

    //Hit rate analysis

    {
    QString pythonScriptPath = ":/piecharts.py";  // Replace with your actual path

        // Read Python script content into a string
        QFile file(pythonScriptPath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file:" << pythonScriptPath;
            return;
        }

        QTextStream in(&file);
        QString pythonScript = in.readAll();

        file.close();

        double L1Hit = randMemory->getL1().getAccessNum() == 0 ? 0 : double(randMemory->getL1().getHits()) / double(randMemory->getL1().getAccessNum());
        double L2Hit = randMemory->getL2().getAccessNum() == 0 ? 0 : double(randMemory->getL2().getHits()) / double(randMemory->getL2().getAccessNum());
        double L3Hit = randMemory->getL3().getAccessNum() == 0 ? 0 : double(randMemory->getL3().getHits()) / double(randMemory->getL3().getAccessNum());
        double ramHit = randMemory->getRAM().getAccessNum() == 0 ? 0 : double(randMemory->getRAM().getHits()) / double(randMemory->getRAM().getAccessNum());
        QString str1 = QString::number(L1Hit);
        QString str2 = QString::number(L2Hit);
        QString str3 = QString::number(L3Hit);
        QString str4 = QString::number(ramHit);
        qDebug() << str1 << str2 <<  str3 << str4;

        // Prepare command arguments (excluding the script name itself)
        QStringList arguments;
        arguments << str1 << str4 << str2 << str3;

        // Execute the Python script using QProcess
        QProcess process;
        process.start("python", QStringList() << "-c" << pythonScript << arguments);
        process.waitForFinished();

        // Check exit code and output
        int exitCode = process.exitCode();
        QString output = QString(process.readAllStandardOutput());

        qDebug() << "Exit code:" << exitCode;
        qDebug() << "Output:" << output;
    }

    //AMAT analysis

    {
    QString pythonScriptPath = ":/AMATs.py";  // Replace with your actual path

        // Read Python script content into a string
        QFile file(pythonScriptPath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file:" << pythonScriptPath;
            return;
        }

        QTextStream in(&file);
        QString pythonScript = in.readAll();

        file.close();

        double L1AMAT = randMemory->getL1().getAMAT();
        double L2AMAT = randMemory->getL2().getAMAT();
        double L3AMAT = randMemory->getL3().getAMAT();
        double ramAMAT = randMemory->getRAM().getAMAT();
        QString str1 = QString::number(L1AMAT);
        QString str2 = QString::number(L2AMAT);
        QString str3 = QString::number(L3AMAT);
        QString str4 = QString::number(ramAMAT);

        // Prepare command arguments (excluding the script name itself)
        QStringList arguments;
        arguments << str1 << str4 << str2 << str3;

        // Execute the Python script using QProcess
        QProcess process;
        process.start("python", QStringList() << "-c" << pythonScript << arguments);
        process.waitForFinished();

        // Check exit code and output
        int exitCode = process.exitCode();
        QString output = QString(process.readAllStandardOutput());

        qDebug() << "Exit code:" << exitCode;
        qDebug() << "Output:" << output;
    }
}
