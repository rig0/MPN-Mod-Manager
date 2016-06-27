#ifndef MODMANAGER_H
#define MODMANAGER_H

#include <QMainWindow>

namespace Ui {
class ModManager;
}

class ModManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModManager(QWidget *parent = 0);
    ~ModManager();

private slots:
    void on_mad08_clicked();

    void on_mad17_clicked();

private:
    Ui::ModManager *ui;
};

#endif // MODMANAGER_H
