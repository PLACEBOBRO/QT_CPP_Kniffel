//Name 1: Fabian Schiller
//Matrikel 1: 1859390
//Note 1: NEIN
//Schein 1: NEIN
//ist für den Wahlbereich, daher nur bestanden oder nicht bestanden


#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("background-color:#e5d6a3;");
    w.show();

    return a.exec();
}
