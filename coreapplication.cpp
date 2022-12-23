#include "coreapplication.h"

coreApplication::coreApplication(int argc, char *argv[]) : QApplication(argc, argv)
{
    gui = new GUI;
}

// запуск приложения
int coreApplication::run()
{
    gui->showGamingWindow();

    return this->exec();
}
