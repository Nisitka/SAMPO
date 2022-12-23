#ifndef COREAPPLICATION_H
#define COREAPPLICATION_H

#include <QObject>

#include <QApplication>

class coreApplication : public QApplication
{
public:
    coreApplication(int argc, char *argv[]);

    int run();
};

#endif // COREAPPLICATION_H
