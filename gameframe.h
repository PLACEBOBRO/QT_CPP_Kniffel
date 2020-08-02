#ifndef GAMEFRAME_H
#define GAMEFRAME_H

#include <QDialog>

namespace Ui {
class GameFrame;
}

class GameFrame : public QDialog
{
    Q_OBJECT

public:
    explicit GameFrame(QWidget *parent = nullptr);
    ~GameFrame();

private slots:
    void on_wuerfeln_clicked();

private:
    Ui::GameFrame *ui;
};

#endif // GAMEFRAME_H
