#include "gameframe.h"
#include "ui_gameframe.h"
#include <time.h>
#include <stdlib.h>
#include <QDebug>
#include <string.h>

using namespace std;

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
    }
    ui->dice1->display(dices[0]);
    ui->dice2->display(dices[1]);
    ui->dice3->display(dices[2]);
    ui->dice4->display(dices[3]);
    ui->dice5->display(dices[4]);
    ui->wuerfeln->setEnabled(false);
}


int generateSum(int trigger){
    int sum = 0;
    for (int i=0;i<dices_size;i++){
        if(dices[i] == trigger){
            sum += trigger;
        }
    }
    return sum;
}

void GameFrame::on_button_einser_clicked()
{
    ui->einser->setText(QString::number(generateSum(1)));
    ui->wuerfeln->setEnabled(true);
}

void GameFrame::on_button_zweier_clicked()
{
    ui->zweier->setText(QString::number(generateSum(2)));
    ui->wuerfeln->setEnabled(true);
}

void GameFrame::on_button_dreier_clicked()
{
    ui->dreier->setText(QString::number(generateSum(3)));
    ui->wuerfeln->setEnabled(true);
}

void GameFrame::on_button_vierer_clicked()
{
    ui->vierer->setText(QString::number(generateSum(4)));
    ui->wuerfeln->setEnabled(true);
}

void GameFrame::on_button_fuenfer_clicked()
{
    ui->fuenfer->setText(QString::number(generateSum(5)));
    ui->wuerfeln->setEnabled(true);
}

void GameFrame::on_button_sechser_clicked()
{
    ui->sechser->setText(QString::number(generateSum(6)));
    ui->wuerfeln->setEnabled(true);
}
