#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameframe.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    this->close();
    GameFrame game;
    game.setModal(true);
    game.exec();
}
