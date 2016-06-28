#define WINVER 0x0600
#define _WIN32_WINNT 0x0600
#include "modmanager.h"
#include "ui_modmanager.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <sys/stat.h>
#include <QMessageBox>
#include <QFile>
#include <QDir>

//----------MPN MOD MANAGER BY RAMBORIGS----------//

using namespace std;

char line[100];
char endlist = '[';
string UsrDir_s = getenv("USERPROFILE");
string MadDir_s = UsrDir_s + "\\Documents\\Madden NFL 08\\";
string ModDir_s = MadDir_s + "Mods\\";
string firstMad = MadDir_s + "DB_TEAMS.dat";
string lastMad = MadDir_s + "ver.zip";
QString curDir_qs = QDir::currentPath();
QString curINI_qs = curDir_qs + "/modlist.ini";

inline bool FileStatus (const string& fileName)
{
  struct stat buffer;
  return (stat (fileName.c_str(), &buffer) == 0);
}

ModManager::ModManager(QWidget *parent) :
    QMainWindow(parent /*, Qt::FramelessWindowHint */ ),
    ui(new Ui::ModManager)
{
    ui->setupUi(this);

    //----------MAKING SURE REQUIRED FOLDERS AND FILES EXSIST BEFORE RUNNING----------//

    if (FileStatus(MadDir_s) == 0)
        {
            QMessageBox msgBox;
            msgBox.setIconPixmap(QPixmap(":/res/imgs/error.png"));
            msgBox.setWindowTitle("Madden NFL 08 Directory not found!");
            msgBox.setText("\"Documents/Madden NFL 08\" directory does not exsist!");
            msgBox.exec();
            exit (EXIT_FAILURE);
        }
    if (FileStatus(ModDir_s) == 0)
        {
            QMessageBox msgBox;
            msgBox.setIconPixmap(QPixmap(":/res/imgs/error.png"));
            msgBox.setWindowTitle("Mods Directory not found!");
            msgBox.setText("\"Documents/Madden NFL 08/Mods\" directory does not exsist!");
            msgBox.exec();
            exit (EXIT_FAILURE);
        }
    string firstMod = ModDir_s + "DB_TEAMS.dat";
    if (FileStatus(firstMod) == 0)
        {
            QMessageBox msgBox;
            msgBox.setIconPixmap(QPixmap(":/res/imgs/error.png"));
            msgBox.setWindowTitle("Mods missing!");
            msgBox.setText("\"Documents/Madden NFL 08/Mods\" appears to be missing mods!");
            msgBox.exec();
            exit (EXIT_FAILURE);
        }
    if (FileStatus(curINI_qs.toStdString()) == 0)
        {
            QFile::copy(":/res/modlist.ini", curINI_qs);
        }

    //----------CHECKING IF MODS ARE ENABLED UPON LAUNCHING----------//

    if ((FileStatus(firstMad)) && (FileStatus(lastMad)) == 1)
        {
            ui->ModStatus->setStyleSheet("QGraphicsView {background-image: url("":/res/imgs/enabled.png""); }");
        }
        else
        {
            ui->ModStatus->setStyleSheet("QGraphicsView {background-image: url("":/res/imgs/disabled.png""); }");
        }
}

ModManager::~ModManager()
{
    delete ui;
}

//----------REMOVING HARDLINKS UPON CLIKING 'ORIGINAL' BUTTON----------//

void ModManager::on_mad08_clicked()
{
        line[0] = '\0';
        ifstream ModList2 (curINI_qs.toStdString().c_str());
        ModList2.getline(line, 100, ']');
        ModList2.ignore();
            while (line[4] != endlist)
            {
                ModList2.getline(line, 100, ';');
                ModList2.ignore();
                    if (line[0] == endlist)
                    {
                        break;
                    }
                string DelSymLink_s = MadDir_s + line;
                remove(DelSymLink_s.c_str());
            }
        ModList2.close();
        ui->ModStatus->setStyleSheet("QGraphicsView {background-image: url("":/res/imgs/disabled.png""); }");
}

//----------CREATING HARDSLINKS UPON CLIKING 'MODDED' BUTTON----------//

void ModManager::on_mad17_clicked()
{
        if ((FileStatus(firstMad)) && (FileStatus(lastMad)) != 0)
        {
            QMessageBox msgBox;
            msgBox.setIconPixmap(QPixmap(":/res/imgs/info.png"));
            msgBox.setWindowTitle("Oops...");
            msgBox.setText("Mods are already enabled!");
            msgBox.exec();
        }
        else
        {
            ifstream ModList (curINI_qs.toStdString().c_str());
            ModList.getline(line, 100, ']');
            ModList.ignore();
                while (line[4] != endlist)
                {
                    ModList.getline(line, 100, ';');
                    ModList.ignore();
                        if (line[0] == endlist)
                        {
                            break;
                        }
                    string TargetLink_s = ModDir_s + line;
                    string SymLink_s = MadDir_s + line;
                    const char* TargetLink_cc = TargetLink_s.c_str();
                    const char* SymLink_cc = SymLink_s.c_str();
                    CreateHardLinkA(SymLink_cc, TargetLink_cc, 0);
                }
            ModList.close();
            ui->ModStatus->setStyleSheet("QGraphicsView {background-image: url("":/res/imgs/enabled.png""); }");
        }
}
