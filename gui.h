#ifndef GUI_H
#define GUI_H

#include <QObject>

#include "window.h"

class GUI
{
public:
    GUI();

    void showGamingWindow();

private:
    window* mainWindow;
};

#endif // GUI_H
