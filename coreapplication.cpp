#include "coreapplication.h"

coreApplication::coreApplication(int argc, char *argv[]) : QApplication(argc, argv)
{
    gui = new GUI;
    player = new Belic();         /// Инициализируем игрока

    gui->setPlayer(player);

    // помещаем интерфейс в отдельный поток
    guiThread = new QThread;
    guiThread->start();
    gui->moveToThread(guiThread);
}

// запуск приложения
int coreApplication::run()
{
    gui->showGamingWindow();

    return this->exec();
}
