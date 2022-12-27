#ifndef COREAPPLICATION_H
#define COREAPPLICATION_H

#include <QApplication>

#include "gui.h"
#include "belic.h"

#include <QThread>

class coreApplication : public QApplication
{
public:
    coreApplication(int argc, char *argv[]);

    int run();

private:
    GUI* gui;
    QThread* guiThread;

    // персонаж, которым мы будем управлять
    Player* player;
};

#endif // COREAPPLICATION_H
