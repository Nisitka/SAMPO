#include "coreapplication.h"

coreApplication::coreApplication(int argc, char *argv[]) : QApplication(argc, argv)
{

}

// запуск приложения
int coreApplication::run()
{
    return this->exec();
}
