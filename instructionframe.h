#ifndef INSTRUCTIONFRAME_H
#define INSTRUCTIONFRAME_H

#include <QDialog>

namespace Ui {
class instructionFrame;
}

class instructionFrame : public QDialog
{
    Q_OBJECT

public:
    explicit instructionFrame(QWidget *parent = nullptr);
    ~instructionFrame();

private slots:
    void on_pushButton_clicked();

private:
    Ui::instructionFrame *ui;
};

#endif // INSTRUCTIONFRAME_H
