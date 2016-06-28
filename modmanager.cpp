#define WINVER 0x0600
#define _WIN32_WINNT 0x0600
#include "modmanager.h"
#include "ui_modmanager.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <sys/stat.h>
#include <QMessageBox>

//----------MPN MOD MANAGER BY RAMBORIGS----------//

using namespace std;

char line[100];
char endlist = '[';
string UsrDir_s = getenv("USERPROFILE");
string MadDir_s = UsrDir_s + "\\Documents\\Madden NFL 08\\";
string ModDir_s = MadDir_s + "Mods\\";
string UserINI_s = ModDir_s + "Manager\\modlist.ini"; //--LIST OF ALL MODS LOCATED HERE--//
const char* MadDir_cc= MadDir_s.c_str();
const char* ModDir_cc= ModDir_s.c_str();
const char* UserINI_cc = UserINI_s.c_str();

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

    //----------MAKING SURE REQUIRED FOLDERS AND FILES EXIST BEFORE RUNNING----------//

    if (FileStatus(MadDir_s) == 0)
        {
            QMessageBox msgBox;
            msgBox.setText("\"Documents/Madden NFL 08\" directory does not exsist!");
            msgBox.exec();
            exit (EXIT_FAILURE);
        }
    if (FileStatus(ModDir_s) == 0)
        {
            QMessageBox msgBox;
            msgBox.setText("\"Documents/Madden NFL 08/Mods\" directory does not exsist!");
            msgBox.exec();
            exit (EXIT_FAILURE);
        }
    string firstMod = ModDir_s + "DB_TEAMS.dat";
    if (FileStatus(firstMod) == 0)
        {
            QMessageBox msgBox;
            msgBox.setText("\"Documents/Madden NFL 08/Mods\" appears to be missing mods. Re-download the files.");
            msgBox.exec();
            exit (EXIT_FAILURE);
        }

    //----------CHECKING IF MODS ARE ENABLED UPON LAUNCHING----------//

    string firstMad = MadDir_s + "DB_TEAMS.dat";
    string lastMad = MadDir_s + "ver.zip";
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

//----------REMOVING SYMLINKS UPON CLIKING 'ORIGINAL' BUTTON----------//

void ModManager::on_mad08_clicked()
{
        line[0] = '\0';
        ifstream ModList2 (UserINI_cc);
        ModList2.getline(line, 100, ']');
        ModList2.ignore();
        while (line[4] != endlist)
            {
                ModList2.getline(line, 100, ';');
                ModList2.ignore();
                if (line[0] == endlist){
                    break;
                }
                string DelSymLink_s = MadDir_s + line;
                remove(DelSymLink_s.c_str());
            }
        ModList2.close();
        ui->ModStatus->setStyleSheet("QGraphicsView {background-image: url("":/res/imgs/disabled.png""); }");
}

//----------CREATING SYMLINKS UPON CLIKING 'MODDED' BUTTON----------//

void ModManager::on_mad17_clicked()
{
        ifstream ModList (UserINI_cc);
        ModList.getline(line, 100, ']');
        ModList.ignore();
        while (line[4] != endlist)
            {
                ModList.getline(line, 100, ';');
                ModList.ignore();
                if (line[0] == endlist){
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
