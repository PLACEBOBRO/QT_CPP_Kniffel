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

    void on_button_einser_clicked();

    void on_button_zweier_clicked();

    void on_button_dreier_clicked();

    void on_button_vierer_clicked();

    void on_button_fuenfer_clicked();

    void on_button_sechser_clicked();

    void on_button_drp_clicked();

    void on_buttonvip_clicked();

    void on_button_fh_clicked();

    void on_button_ks_clicked();

    void on_button_gs_clicked();

    void on_button_kniffel_clicked();

    void on_button_chance_clicked();

    void on_pushButton_clicked();

    void calculateOverallScore();

    void calculateScoreTop();

    void calculateScoreBottom();

    void on_reroll_clicked();

    void resetRerollCounter();

    void on_restart_clicked();

private:
    Ui::GameFrame *ui;
};

#endif // GAMEFRAME_H
