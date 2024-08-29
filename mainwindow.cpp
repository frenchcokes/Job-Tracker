#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabelName(const QString &name)
{
    qInfo() << "PRINTED LABEL";
    ui->label->setText(name);
}

QString MainWindow::name() const
{
    return ui->label->text();
}
