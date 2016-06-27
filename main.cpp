#include "modmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModManager w;
    w.show();

    return a.exec();
}
