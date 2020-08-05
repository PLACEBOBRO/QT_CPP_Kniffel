/********************************************************************************
** Form generated from reading UI file 'instructionframe.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTIONFRAME_H
#define UI_INSTRUCTIONFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_instructionFrame
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *pushButton;

    void setupUi(QDialog *instructionFrame)
    {
        if (instructionFrame->objectName().isEmpty())
            instructionFrame->setObjectName(QString::fromUtf8("instructionFrame"));
        instructionFrame->resize(1002, 724);
        verticalLayoutWidget = new QWidget(instructionFrame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 40, 961, 631));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout->addWidget(label_13);

        label_14 = new QLabel(instructionFrame);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(460, 10, 80, 21));
        pushButton = new QPushButton(instructionFrame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(870, 680, 106, 30));

        retranslateUi(instructionFrame);

        QMetaObject::connectSlotsByName(instructionFrame);
    } // setupUi

    void retranslateUi(QDialog *instructionFrame)
    {
        instructionFrame->setWindowTitle(QApplication::translate("instructionFrame", "Dialog", nullptr));
        label->setText(QApplication::translate("instructionFrame", "# 1er - hier werden alle gew\303\274rfelten Einser addiert. ", nullptr));
        label_2->setText(QApplication::translate("instructionFrame", "# 2er - hier werden alle gew\303\274rfelten Zweier addiert. ", nullptr));
        label_3->setText(QApplication::translate("instructionFrame", "# 3er - hier werden alle gew\303\274rfelten Dreier addiert. ", nullptr));
        label_5->setText(QApplication::translate("instructionFrame", "# 4er - hier werden alle gew\303\274rfelten Vierer addiert. ", nullptr));
        label_4->setText(QApplication::translate("instructionFrame", "# 5er - hier werden alle gew\303\274rfelten F\303\274nfer addiert. ", nullptr));
        label_6->setText(QApplication::translate("instructionFrame", "# 6er - hier werden alle gew\303\274rfelten Sechser addiert. ", nullptr));
        label_7->setText(QApplication::translate("instructionFrame", "# Dreierpasch - mindestens dreimal dieselbe Zahl - alle Augen werden zusammengez\303\244hlt. ", nullptr));
        label_8->setText(QApplication::translate("instructionFrame", "# Viererpasch - mindestens viermal dieselbe Zahl - alle Augen werden zusammengez\303\244hlt. ", nullptr));
        label_9->setText(QApplication::translate("instructionFrame", "# Full-House - je dreimal und zweimal gleiche Zahlen, 25 Punkte werden in das Feld eintragen. ", nullptr));
        label_10->setText(QApplication::translate("instructionFrame", "# Kleine Stra\303\237e - W\303\274rfelkombination von 1-4, 2-5 oder 3-6, 30 Punkte werden in das Feld eintragen. ", nullptr));
        label_11->setText(QApplication::translate("instructionFrame", "# Gro\303\237e Stra\303\237e - W\303\274rfelkombination von 1-5 oder 2-6, 40 Punkte werden in das Feld eintragen. ", nullptr));
        label_12->setText(QApplication::translate("instructionFrame", "# Kniffel - f\303\274nfmal die gleiche Zahl, 50 Punkte werden in das Feld eingetragen. ", nullptr));
        label_13->setText(QApplication::translate("instructionFrame", "# Chance - hier muss nichts zusammenpassen. Alle Augen werden zusammengez\303\244hlt. ", nullptr));
        label_14->setText(QApplication::translate("instructionFrame", "Anleitung", nullptr));
        pushButton->setText(QApplication::translate("instructionFrame", "Zur\303\274ck", nullptr));
    } // retranslateUi

};

namespace Ui {
    class instructionFrame: public Ui_instructionFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTIONFRAME_H
