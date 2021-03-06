#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameframe.h"
#include "instructionframe.h"
#include <QMediaPlaylist>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Background music
    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/backgroundmusic.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(playlist);
    music->setVolume(20);
    music->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Open Game window
void MainWindow::on_startButton_clicked()
{
    this->close();
    GameFrame game;
    game.setStyleSheet("background-color:#e5d6a3;");
    game.setModal(true);
    game.exec();
}

// Open settings window
void MainWindow::on_settingsButton_clicked()
{
    instructionFrame ins;
    ins.setStyleSheet("background-color:#e5d6a3;");
    ins.setModal(true);
    ins.exec();
}

// Close window
void MainWindow::on_endButton_clicked()
{
    this->close();
}
