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

int isStreet(){
    int counter = 1;
    int result = 0;
    for(int i=1;i<dices_size;i++){
        if(dices[i] == dices[i-1]){
            continue;
        }
        if(dices[i] == dices[i-1]+1){
            counter++;
        }else{
            counter = 1;
        }
    }
    if(counter >= 4){
        result = 1;
    }
    if(counter == 5){
        result = 2;
    }
    return result;

}

int isPasch(){
    int counter = 1;
    int result = 0;
    for (int i=1;i<dices_size;i++) {
        if(dices[i] == dices[i-1]){
            counter++;
        }else{
            counter = 1;
        }
    }
    if(counter == 3){
        result = 1;
    }
    if(counter >= 4){
        result = 2;
    }
    qDebug() << result;
    return result;
}

int isKniffel(){
    if(dices[0] == dices[1] == dices[2] == dices[3] == dices[4]){
        return 1;
    }
    return 0;
}

int isFullHouse(){
    if(dices[0] == dices[1] == dices[2] && dices[3] == dices[4]){
        return 1;
    }
    return 0;
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

int generateSumAllDices(){
    int sum = 0;
    for(int i=0;i<dices_size;i++){
        sum += dices[i];
    }
    return sum;
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
    sort(dices, dices + dices_size);
}

void GameFrame::on_button_einser_clicked()
{
    ui->einser->setText(QString::number(generateSum(1)));
    ui->wuerfeln->setEnabled(true);
    ui->button_einser->setEnabled(false);
}

void GameFrame::on_button_zweier_clicked()
{
    ui->zweier->setText(QString::number(generateSum(2)));
    ui->wuerfeln->setEnabled(true);
    ui->button_zweier->setEnabled(false);
}

void GameFrame::on_button_dreier_clicked()
{
    ui->dreier->setText(QString::number(generateSum(3)));
    ui->wuerfeln->setEnabled(true);
    ui->button_dreier->setEnabled(false);
}

void GameFrame::on_button_vierer_clicked()
{
    ui->vierer->setText(QString::number(generateSum(4)));
    ui->wuerfeln->setEnabled(true);
    ui->button_vierer->setEnabled(false);
}

void GameFrame::on_button_fuenfer_clicked()
{
    ui->fuenfer->setText(QString::number(generateSum(5)));
    ui->wuerfeln->setEnabled(true);
    ui->button_fuenfer->setEnabled(false);
}

void GameFrame::on_button_sechser_clicked()
{
    ui->sechser->setText(QString::number(generateSum(6)));
    ui->wuerfeln->setEnabled(true);
    ui->button_sechser->setEnabled(false);
}

void GameFrame::on_button_drp_clicked()
{
    if(isPasch() == 1 || isPasch() == 2){
        ui->dreierpasch->setText(QString::number(generateSumAllDices()));
    }else{
        ui->dreierpasch->setText("0");
    }
    ui->wuerfeln->setEnabled(true);
    ui->button_drp->setEnabled(false);
}

void GameFrame::on_buttonvip_clicked()
{
    if(isPasch() == 2){
        ui->viererpasch->setText(QString::number(generateSumAllDices()));
    }else{
        ui->viererpasch->setText("0");
    }
    ui->wuerfeln->setEnabled(true);
    ui->buttonvip->setEnabled(false);
}

void GameFrame::on_button_fh_clicked()
{
    if(isFullHouse() == 1){
        ui->fullhouse->setText("25");
    }else{
        ui->fullhouse->setText("0");
    }
    ui->wuerfeln->setEnabled(true);
    ui->button_fh->setEnabled(false);
}

void GameFrame::on_button_ks_clicked()
{
    if(isStreet() == 1 || isStreet() == 2){
        ui->kleinestrasse->setText("30");
    }else{
        ui->kleinestrasse->setText("0");
    }
    ui->wuerfeln->setEnabled(true);
    ui->button_ks->setEnabled(false);
}

void GameFrame::on_button_gs_clicked()
{
    if(isStreet() == 2){
        ui->grossestrasse->setText("40");
    }else{
        ui->grossestrasse->setText("0");
    }
    ui->wuerfeln->setEnabled(true);
    ui->button_gs->setEnabled(false);
}

void GameFrame::on_button_kniffel_clicked()
{
    if(isKniffel() == 1){
        ui->kniffel->setText("50");
    }else{
        ui->kniffel->setText("0");
    }
    ui->wuerfeln->setEnabled(true);
    ui->button_kniffel->setEnabled(false);
}

void GameFrame::on_button_chance_clicked()
{
    ui->chance->setText(QString::number(generateSumAllDices()));
    ui->wuerfeln->setEnabled(true);
    ui->button_chance->setEnabled(false);
}

void GameFrame::on_pushButton_clicked()
{
    this->destroy();
}
