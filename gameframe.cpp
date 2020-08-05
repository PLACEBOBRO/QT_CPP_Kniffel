#include "gameframe.h"
#include "ui_gameframe.h"
#include <time.h>
#include <stdlib.h>
#include <QDebug>
#include <string.h>
#include <QMediaPlayer>

using namespace std;

// variables for initialization
int dices[] = {0,0,0,0,0};
int dices_size = sizeof(dices)/sizeof(dices[0]);
int reroll_counter = 2;
QMediaPlayer * diceroll;

void calculateOverallScore();



GameFrame::GameFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameFrame)
{
    ui->setupUi(this);
    srand(time(NULL));
    calculateOverallScore();

    diceroll = new QMediaPlayer(); // dice roll sound initialization
    diceroll->setMedia(QUrl("qrc:/sounds/diceroll.wav"));
    diceroll->setVolume(100);
}

GameFrame::~GameFrame()
{
    delete ui;
}

// Check if dices are "Straße"
int isSmallStreet(){
    int counter = 1;
    int result = 0;
    for(int i=1;i<dices_size;i++){
        if(dices[i] == dices[i-1]){
            continue;
        }
        if(dices[i-1]+1 == dices[i]){
            counter++;
            if(counter == 4){
                result = 1;
                break;
            }
        }else{
            counter = 1;
        }
    }
    return result;

}

int isBigStreet(){
    for(int i = 1; i < dices_size; i++){
        if(dices[i] != dices[i-1]+1){
            return 0;
        }
    }
    return 1;
}

int is4Pasch(){
    if(dices[0] == dices[1] && dices[1] == dices[2] && dices[2] == dices[3]){
        return 1;
    }
    if(dices[1] == dices[2] && dices[2] == dices[3] && dices[3] == dices[4]){
        return 1;
    }
    return 0;
}

// Check if dices are "Pasch"
int is3Pasch(){
    int counter = 1;
    int result = 0;
    for (int i=1;i<dices_size;i++) {
        if(dices[i] == dices[i-1]){
            counter++;
            if(counter == 3){
                result = 1;
                break;
            }
        }else{
            counter = 1;
        }
    }

    return result;
}

// Check if all dices have the same value
int isKniffel(){
    for(int i = 0; i < dices_size-1; i++){
        if(dices[i] != dices[i+1]){
            return 0;
        }
    }
    return 1;
}

// Check if dices are full house
int isFullHouse(){
    if(dices[0] == dices[1] && dices[1] == dices[2]){
        if(dices[3] == dices[4]){
            return 1;
        }
    }

    if(dices[0] == dices[1]){
        if(dices[2] == dices[3] && dices[3] == dices[4]){
            return 1;
        }
    }
    return 0;
}

// Generate sum of given value
int generateSum(int trigger){
    int sum = 0;
    for (int i=0;i<dices_size;i++){
        if(dices[i] == trigger){
            sum += trigger;
        }
    }
    return sum;
}

// Generate sum of all dices added together
int generateSumAllDices(){
    int sum = 0;
    for(int i=0;i<dices_size;i++){
        sum += dices[i];
    }
    return sum;
}

// Reset reroll button
void GameFrame::resetRerollCounter(){
    reroll_counter = 2;
    ui->reroll->setText("Nochmal würfeln (" + QString::number(reroll_counter) + ")");

}

// Calculate the top score
void GameFrame::calculateScoreTop(){
    int sum = 0;
    sum += (ui->einser->text()).toInt();
    sum += (ui->zweier->text()).toInt();
    sum += (ui->dreier->text()).toInt();
    sum += (ui->vierer->text()).toInt();
    sum += (ui->fuenfer->text()).toInt();
    sum += (ui->sechser->text()).toInt();
    if(sum >= 63){
        sum += 25;
    }
    ui->summe_oben->setText(QString::number(sum));
}

// Calculate the bottom score
void GameFrame::calculateScoreBottom(){
    int sum = 0;
    sum += (ui->dreierpasch->text()).toInt();
    sum += (ui->viererpasch->text()).toInt();
    sum += (ui->fullhouse->text()).toInt();
    sum += (ui->kleinestrasse->text()).toInt();
    sum += (ui->grossestrasse->text()).toInt();
    sum += (ui->kniffel->text()).toInt();
    sum += (ui->chance->text()).toInt();
    ui->summe_unten->setText(QString::number(sum));
}

// Calculate the overall score (top and bottom added together)
void GameFrame::calculateOverallScore(){
    int score = 0;
    score += (ui->summe_unten->text()).toInt();
    score += (ui->summe_oben->text()).toInt();
}

// Dice roll
void GameFrame::on_wuerfeln_clicked()
{
    diceroll->play();
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
    calculateScoreTop();
    calculateScoreBottom();
    calculateOverallScore();
}

// Reroll dice clicked
void GameFrame::on_reroll_clicked()
{
    diceroll->play();
    reroll_counter--;
    on_wuerfeln_clicked();
    ui->reroll->setText("Nochmal würfeln (" + QString::number(reroll_counter) + ")");
    if(reroll_counter == 0){
        ui->reroll->setEnabled(false);
    }

}

/*
 * The following functions are for adding the values on the scoreboard.
 * After every dice roll, the diceroll button is disabled and can only be enabled if
 * one value is set.
 */
void GameFrame::on_button_einser_clicked()
{
    ui->einser->setText(QString::number(generateSum(1)));
    ui->wuerfeln->setEnabled(true);
    ui->reroll->setEnabled(true);
    resetRerollCounter();
    ui->button_einser->setEnabled(false);
}

void GameFrame::on_button_zweier_clicked()
{
    ui->zweier->setText(QString::number(generateSum(2)));
    ui->wuerfeln->setEnabled(true);
    ui->reroll->setEnabled(true);
    resetRerollCounter();
    ui->button_zweier->setEnabled(false);
}

void GameFrame::on_button_dreier_clicked()
{
    ui->dreier->setText(QString::number(generateSum(3)));
    ui->wuerfeln->setEnabled(true);
    ui->reroll->setEnabled(true);
    resetRerollCounter();
    ui->button_dreier->setEnabled(false);
}

void GameFrame::on_button_vierer_clicked()
{
    ui->vierer->setText(QString::number(generateSum(4)));
    ui->wuerfeln->setEnabled(true);
    ui->reroll->setEnabled(true);
    resetRerollCounter();
    ui->button_vierer->setEnabled(false);
}

void GameFrame::on_button_fuenfer_clicked()
{
    ui->fuenfer->setText(QString::number(generateSum(5)));
    ui->wuerfeln->setEnabled(true);
    ui->reroll->setEnabled(true);
    resetRerollCounter();
    ui->button_fuenfer->setEnabled(false);
}

void GameFrame::on_button_sechser_clicked()
{
    ui->sechser->setText(QString::number(generateSum(6)));
    ui->wuerfeln->setEnabled(true);
    ui->reroll->setEnabled(true);
    resetRerollCounter();
    ui->button_sechser->setEnabled(false);
}

void GameFrame::on_button_drp_clicked()
{
    if(is3Pasch() == 1 || is4Pasch() == 1){
        ui->dreierpasch->setText(QString::number(generateSumAllDices()));
    }else{
        ui->dreierpasch->setText("0");
    }
    ui->wuerfeln->setEnabled(true);
    ui->reroll->setEnabled(true);
    resetRerollCounter();
    ui->button_drp->setEnabled(false);
}

void GameFrame::on_buttonvip_clicked()
{
    if(is4Pasch() == 1){
        ui->viererpasch->setText(QString::number(generateSumAllDices()));
    }else{
        ui->viererpasch->setText("0");
    }
    ui->wuerfeln->setEnabled(true);
    ui->reroll->setEnabled(true);
    resetRerollCounter();
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
    ui->reroll->setEnabled(true);
    resetRerollCounter();
    ui->button_fh->setEnabled(false);
}

void GameFrame::on_button_ks_clicked()
{
    if(isSmallStreet() == 1 || isBigStreet() == 1){
        ui->kleinestrasse->setText("30");
    }else{
        ui->kleinestrasse->setText("0");
    }
    ui->wuerfeln->setEnabled(true);
    ui->reroll->setEnabled(true);
    resetRerollCounter();
    ui->button_ks->setEnabled(false);
}

void GameFrame::on_button_gs_clicked()
{
    if(isBigStreet() == 1){
        ui->grossestrasse->setText("40");
    }else{
        ui->grossestrasse->setText("0");
    }
    ui->wuerfeln->setEnabled(true);
    ui->reroll->setEnabled(true);
    resetRerollCounter();
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
    ui->reroll->setEnabled(true);
    resetRerollCounter();
    ui->button_kniffel->setEnabled(false);
}

void GameFrame::on_button_chance_clicked()
{
    ui->chance->setText(QString::number(generateSumAllDices()));
    ui->wuerfeln->setEnabled(true);
    ui->reroll->setEnabled(true);
    resetRerollCounter();
    ui->button_chance->setEnabled(false);
}

// Button for closing the window
void GameFrame::on_pushButton_clicked()
{
    this->close();
}

// Reset all values and dices
void GameFrame::on_restart_clicked()
{
    ui->einser->setText("---");
    ui->zweier->setText("---");
    ui->dreier->setText("---");
    ui->vierer->setText("---");
    ui->fuenfer->setText("---");
    ui->sechser->setText("---");

    ui->dreierpasch->setText("---");
    ui->viererpasch->setText("---");
    ui->fullhouse->setText("---");
    ui->grossestrasse->setText("---");
    ui->kleinestrasse->setText("---");
    ui->kniffel->setText("---");
    ui->chance->setText("---");

    ui->button_einser->setEnabled(true);
    ui->button_zweier->setEnabled(true);
    ui->button_dreier->setEnabled(true);
    ui->button_vierer->setEnabled(true);
    ui->button_fuenfer->setEnabled(true);
    ui->button_sechser->setEnabled(true);
    ui->button_drp->setEnabled(true);
    ui->buttonvip->setEnabled(true);
    ui->button_fh->setEnabled(true);
    ui->button_ks->setEnabled(true);
    ui->button_gs->setEnabled(true);
    ui->button_kniffel->setEnabled(true);
    ui->button_chance->setEnabled(true);

    ui->wuerfeln->setEnabled(true);
    reroll_counter = 2;
    ui->reroll->setText("Nochmal würfeln (" + QString::number(reroll_counter) + ")");
    ui->reroll->setEnabled(true);

    for(int i = 0; i < dices_size; i++){
        dices[i] = 0;
    }
    ui->dice1->display(dices[0]);
    ui->dice2->display(dices[1]);
    ui->dice3->display(dices[2]);
    ui->dice4->display(dices[3]);
    ui->dice5->display(dices[4]);


    calculateScoreTop();
    calculateScoreBottom();
    calculateOverallScore();
}
