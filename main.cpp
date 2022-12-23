#include <QApplication>

#include <QDebug>

#include "coreapplication.h"

int main(int argc, char *argv[])
{
    qDebug() << "Это сампо детка!";

    coreApplication SAMPO(argc, argv);
    SAMPO.run();
}


