#include "gameframe.h"
#include "ui_gameframe.h"
#include <time.h>
#include <stdlib.h>
#include <QDebug>



int dices[] = {0,0,0,0,0};
int dices_size = sizeof(dices)/sizeof(dices[0]);




GameFrame::GameFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameFrame)
{
    ui->setupUi(this);
    srand(time(NULL));
}

GameFrame::~GameFrame()
{
    delete ui;
}

void GameFrame::on_wuerfeln_clicked()
{
    for (int i=0;i<dices_size; i++) {
        dices[i] = rand() % 6 + 1;
        qDebug() << dices[i];
    }
}