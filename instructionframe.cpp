#include "instructionframe.h"
#include "ui_instructionframe.h"

instructionFrame::instructionFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instructionFrame)
{
    ui->setupUi(this);
}

instructionFrame::~instructionFrame()
{
    delete ui;
}

// Button for closing the instructionspage
void instructionFrame::on_pushButton_clicked()
{
    this->close();
}
