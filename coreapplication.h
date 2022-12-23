#ifndef COREAPPLICATION_H
#define COREAPPLICATION_H

#include <QApplication>

#include "gui.h"

class coreApplication : public QApplication
{
public:
    coreApplication(int argc, char *argv[]);

    int run();

private:
    GUI* gui;
};

#endif // COREAPPLICATION_H
