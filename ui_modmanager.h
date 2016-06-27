/********************************************************************************
** Form generated from reading UI file 'modmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODMANAGER_H
#define UI_MODMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModManager
{
public:
    QWidget *centralWidget;
    QPushButton *mad17;
    QPushButton *mad08;
    QGraphicsView *ModStatus;

    void setupUi(QMainWindow *ModManager)
    {
        if (ModManager->objectName().isEmpty())
            ModManager->setObjectName(QStringLiteral("ModManager"));
        ModManager->setWindowModality(Qt::WindowModal);
        ModManager->setEnabled(true);
        ModManager->resize(550, 275);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ModManager->sizePolicy().hasHeightForWidth());
        ModManager->setSizePolicy(sizePolicy);
        ModManager->setMinimumSize(QSize(550, 275));
        ModManager->setMaximumSize(QSize(550, 275));
        ModManager->setStyleSheet(QLatin1String("QMainWindow#ModManager\n"
"{\n"
"   background-image: url(\":/res/imgs/mpnbg1.png\");\n"
"}\n"
"QGraphicsView#ModStatus\n"
"{\n"
"    background-color:rgba(0, 0, 0, 0);\n"
"}\n"
"QPushButton#mad08\n"
"{\n"
"   background-color:rgba(0, 0, 0, 0);\n"
"   background-image: url(\":/res/imgs/08button0.png\");\n"
"}\n"
"QPushButton:hover#mad08\n"
"{\n"
"   background-color:rgba(0, 0, 0, 0);\n"
"   background-image: url(\":/res/imgs/08button1.png\");\n"
"}\n"
"\n"
"QPushButton#mad17\n"
"{\n"
"   background-color:rgba(0, 0, 0, 0);\n"
"   background-image: url(\":/res/imgs/17button0.png\");\n"
"}\n"
"QPushButton:hover#mad17\n"
"{\n"
"   background-color:rgba(0, 0, 0, 0);\n"
"   background-image: url(\":/res/imgs/17button1.png\");\n"
"}\n"
""));
        centralWidget = new QWidget(ModManager);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mad17 = new QPushButton(centralWidget);
        mad17->setObjectName(QStringLiteral("mad17"));
        mad17->setGeometry(QRect(287, 141, 200, 100));
        mad08 = new QPushButton(centralWidget);
        mad08->setObjectName(QStringLiteral("mad08"));
        mad08->setGeometry(QRect(63, 141, 200, 100));
        ModStatus = new QGraphicsView(centralWidget);
        ModStatus->setObjectName(QStringLiteral("ModStatus"));
        ModStatus->setGeometry(QRect(160, 70, 230, 50));
        ModStatus->setInteractive(true);
        ModManager->setCentralWidget(centralWidget);

        retranslateUi(ModManager);

        QMetaObject::connectSlotsByName(ModManager);
    } // setupUi

    void retranslateUi(QMainWindow *ModManager)
    {
        ModManager->setWindowTitle(QApplication::translate("ModManager", "MPN Mod Manager", 0));
        mad17->setText(QString());
        mad08->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ModManager: public Ui_ModManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODMANAGER_H
